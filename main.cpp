#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

// clasa produs
class Product {
    static int generalID; // id ul care tine evidenta numarui de obiecte instantiate
    const int ID; // id ul personal al obiectului
    string name;
    float price;
    int stock;
    string type; // Instrument, vinyl, cd etc

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

class User {
    static int generalID; // id pentru toate instantele obiectului
    const int ID;       // id personal instanta
    string firstName;
    string lastName;
    string email;
    string role; // angajat, administrator, cumpărător

public:
    //constructor cu toti parametrii
    User(const string &first_name, const string &last_name, const string &email, const string &role)
        : ID(generalID++), firstName(first_name), lastName(last_name), email(email), role(role) {}

    //destructor
    ~User() = default;

    //getteri
    const string &getEmail() const { return email; }
    const string &getRole() const { return role; }

    //supraincarea operatorului de afisare
    friend ostream &operator<<(ostream &os, const User &obj) {
        return os << "ID: " << obj.ID
                  << " | Name: " << obj.firstName << " " << obj.lastName
                  << " | Email: " << obj.email
                  << " | Role: " << obj.role;
    }
};
//instantierea variabilei statice
int User::generalID = 1;

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
        os << "Total: " << obj.totalPrice << "\n";
        return os;
    }
};
//instantierea variabilei statice
int Order::generalID = 1;

//clasa de magazin
class Shop {
    static int generalID; // id static pentru generarea id urilor instantelor
    const int ID; // id ul personal al instantelor
    string address;
    vector<Product> products; // vector de produse
public:
    //constructorul cu toti parametrii
    Shop(const string &address, const vector<Product> &products)
        : ID(generalID++), address(address), products(products) {}


    // const product &p = o referinta la un produs p care este constanta, pentru a nu putea fi modificata ( vreau doar sa adaug, fara sa duplic)
    void addProduct(const Product &p) { products.push_back(p); }

    //stergerea unui produs dupa nume din magazin
    void removeProductByName(const string &name) {
        for (auto it = products.begin(); it != products.end(); ) { // parcurg vectorul de produse
            if (it->getName() == name) { // daca numele produsului la care am ajuns este numele produsului pe care vreau sa il sterg
                it = products.erase(it); // sterg produsul
            } else {
                ++it; // trec la urmatorul
            }
        }
    }

    // calculez pretul tuturor produselor din magazin
    float calculateInventoryValue() const {
        float total = 0;
        for (const auto &p : products)
            total += p.getPrice() * p.getStock();
        return total;
    }
    //supraincarcarea operatorului de afisare
    friend ostream &operator<<(ostream &os, const Shop &obj) {
        os << "Shop ID: " << obj.ID << "\nAddress: " << obj.address << "\nProducts:\n";
        for (const auto &p : obj.products) os << "   " << p << "\n";
        return os;
    }
};
//initializarea variabilei statice
int Shop::generalID = 1;

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

    //creez comanda
    Order order(user, {products[0], products[2]});
    fin.close();

    cout << "=== Shop ===\n" << shop << "\n";
    cout << "=== Order ===\n" << order << "\n";
    cout << "Inventory value: " << shop.calculateInventoryValue() << " RON\n";

    return 0;
}
