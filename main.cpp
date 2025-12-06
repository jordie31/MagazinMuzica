#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "User.h"
using namespace std;

// clasa produs
class Product {
    static int generalID; // id ul care tine evidenta numarui de obiecte instantiate
    const int ID; // id ul personal al obiectului
    string name;
    float price;
    int stock;
    string type; // instrument, vinyl, cd etc.

public:
    //constructorul cu toti parametrii
    //const string &name e folosit ca sa nu se mai creeze o copie a stringului,
    //si pentru a nu putea fi folosita adresa ca sa se modifice variabila din clasa
    Product(const string &name, float price, int stock, const string &type)
        : ID(generalID++), name(name), price(price), stock(stock), type(type) {}

    // constructorul de copiere
    Product(const Product &other)
        : ID(generalID++), name(other.name), price(other.price), stock(other.stock), type(other.type) {}

    // destructorul
    ~Product() = default;

    //supraincarcarea operatorului egal
    Product &operator=(const Product &other) {
        if (this == &other) return *this;
        name = other.name;
        price = other.price;
        stock = other.stock;
        type = other.type;
        return *this;
    }

    // reduce stocul
    void reduceStock(int amount) {
        if (amount > stock) amount = stock;
        stock -= amount;
    }

    //getteri
    float getPrice() const { return price; }
    const string &getName() const { return name; }
    int getStock() const { return stock; }

    //supraincarcarea operatorului de afisare
    friend ostream &operator<<(ostream &os, const Product &obj) {
        return os << "ID: " << obj.ID
                  << " | name: " << obj.name
                  << " | price: " << obj.price
                  << " | stock: " << obj.stock
                  << " | type: " << obj.type;
    }
};
//instantierea variabilei statice
int Product::generalID = 1;

//clasa comanda
class Order {
    static int generalID; // id static pentru toate instantele clasei
    const int ID; // id personal per instanta
    User buyer;    // userul care face comanda
    vector<Product> products; // vecotr de produse
    float totalPrice = 0;

public:
    //constructor cu toti parametrii
    Order(const User &buyer, const vector<Product> &products)
        : ID(generalID++), buyer(buyer), products(products) {
        calculateTotal();
    }
    // calculeaza pretul total al produselor din comanda
    void calculateTotal() {
        totalPrice = 0;
        // parcurgerea vectorului de produse si adaugarea pretului fiecarui produs la suma totala
        for (const auto &p : products)
            totalPrice += p.getPrice();

    }
    // getter
    float getTotal() const { return totalPrice; }

    // supraincarcarea operatorului de afisare
    friend ostream &operator<<(ostream &os, const Order &obj) {
        os << "Order ID: " << obj.ID << "\nBuyer: " << obj.buyer << "\nProducts:\n";
        for (const auto &p : obj.products) os << "   " << p << "\n";
        os << "Total price: " << obj.totalPrice << "\n";
        return os;
    }
};
//instantierea variabilei statice
int Order::generalID = 1;

//clasa de magazin


int main() {
    ifstream fin("tastatura.txt"); // fac legatura cu fisierul tastatura.txt
    if (!fin.is_open()) { // testez daca s a putut deschide fisierul
        cout << "Eroare: nu s-a putut deschide fisierul tastatura.txt\n";
        return 1;
    }

    int n;
    fin >> n;
    if (!fin || n <= 0) { // testez daca numarul introdus este un numar valid
        cerr << "Eroare: numar invalid de produse in fisier.\n";
        return 1;
    }

    //citesc produsele din fisier
    vector<Product> products;
    for (int i = 0; i < n; ++i) {
        string name, type;
        float price;
        int stock;
        fin >> name >> price >> stock >> type; // citesc valorile din fisier
        if (!fin) {
            cout << "Eroare la citirea produsului " << i << ".\n";
            return 1;
        }
        products.emplace_back(name, price, stock, type); // creez produsul si il pun la finalul vectorului
    }

    //citesc userii
    string first, last, email, role;
    if (!(fin >> first >> last >> email >> role)) {
        cout << "Eroare la citirea utilizatorului.\n";
        return 1;
    }
    User user(first, last, email, role); //creez userul

    //citesc adresa pentru magazin
    string address;
    if (!(fin >> address)) {
        cout << "Eroare la citirea adresei magazinului.\n";
        return 1;
    }
    Shop shop(address, products); //creez magazinul

    // verific daca exista cele 3 produse
    if (products.size() < 3) {
        cout << "Eroare: sunt necesare cel putin 3 produse pentru a crea comanda.\n";
        return 1;
    }

    //creez comanda (am scazut stocul de dinainte sa fac comanda ca sa se afiseze cu stocul deja scazut)
    products[0].reduceStock(1);  // scadem 1 bucata din primul produs
    products[2].reduceStock(1);  // scadem 1 bucata din al treilea produs

    Order order(user, {products[0], products[2]});
    fin.close();

    Shop updatedShop(address, products);

    cout << "=== Shop ===\n" << shop << "\n";
    cout << "=== Order ===\n" << order << "\n";
    cout << "Inventory value before order: " << shop.calculateInventoryValue() << " RON\n";
    cout << "Inventory value after order: " << updatedShop.calculateInventoryValue() << " RON\n";
    return 0;
}
