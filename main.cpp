#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Product {
    static int generalID;
    const int ID;
    string name;
    float price;
    int stock;
    string type; // Instrument, vinyl, cd etc

public:
    Product(const string &name, float price, int stock, const string &type)
        : ID(generalID++), name(name), price(price), stock(stock), type(type) {}

    Product(const Product &other)
        : ID(generalID++), name(other.name), price(other.price), stock(other.stock), type(other.type) {}

    ~Product() = default;

    Product &operator=(const Product &other) {
        if (this == &other) return *this;
        name = other.name;
        price = other.price;
        stock = other.stock;
        type = other.type;
        return *this;
    }

    void reduceStock(int amount) {
        if (amount > stock) amount = stock;
        stock -= amount;
    }

    float getPrice() const { return price; }
    const string &getName() const { return name; }
    int getStock() const { return stock; }

    friend ostream &operator<<(ostream &os, const Product &obj) {
        return os << "ID: " << obj.ID
                  << " | name: " << obj.name
                  << " | price: " << obj.price
                  << " | stock: " << obj.stock
                  << " | type: " << obj.type;
    }
};
int Product::generalID = 0;

class User {
    static int generalID;
    const int ID;
    string firstName;
    string lastName;
    string email;
    string role; // angajat, administrator, cumpărător

public:
    User(const string &first_name, const string &last_name, const string &email, const string &role)
        : ID(generalID++), firstName(first_name), lastName(last_name), email(email), role(role) {}

    ~User() = default;

    const string &getEmail() const { return email; }
    const string &getRole() const { return role; }

    friend ostream &operator<<(ostream &os, const User &obj) {
        return os << "ID: " << obj.ID
                  << " | Name: " << obj.firstName << " " << obj.lastName
                  << " | Email: " << obj.email
                  << " | Role: " << obj.role;
    }
};
int User::generalID = 0;

class Order {
    static int generalID;
    const int ID;
    User buyer;
    vector<Product> products;
    float totalPrice = 0;

public:
    Order(const User &buyer, const vector<Product> &products)
        : ID(generalID++), buyer(buyer), products(products) {
        calculateTotal();
    }

    void calculateTotal() {
        totalPrice = 0;
        for (const auto &p : products) totalPrice += p.getPrice(); //imi parcurge vectorul de produse automat, nu mai fac cu int i etc
    }

    float getTotal() const { return totalPrice; }

    friend ostream &operator<<(ostream &os, const Order &obj) {
        os << "Order ID: " << obj.ID << "\nBuyer: " << obj.buyer << "\nProducts:\n";
        for (const auto &p : obj.products) os << "   " << p << "\n";
        os << "Total: " << obj.totalPrice << "\n";
        return os;
    }
};
int Order::generalID = 0;

class Shop {
    static int generalID;
    const int ID;
    string address;
    vector<Product> products;
public:
    Shop(const string &address, const vector<Product> &products)
        : ID(generalID++), address(address), products(products) {}


    // const product &p = o referinta la un produs p care este constanta, pentru a nu putea fi modificata ( vreau doar sa adaug, fara sa duplic)
    void addProduct(const Product &p) { products.push_back(p); }

    void removeProductByName(const string &name) {
        products.erase(remove_if(products.begin(), products.end(),
                                 [&](const Product &p){ return p.getName() == name; }),
                       products.end());
    }

    float calculateInventoryValue() const {
        float total = 0;
        for (const auto &p : products)
            total += p.getPrice() * p.getStock();
        return total;
    }

    friend ostream &operator<<(ostream &os, const Shop &obj) {
        os << "Shop ID: " << obj.ID << "\nAddress: " << obj.address << "\nProducts:\n";
        for (const auto &p : obj.products) os << "   " << p << "\n";
        return os;
    }
};
int Shop::generalID = 0;

int main() {
    //initierea obiectelor cu date din fisierul tastatura.txt
    ifstream fin("tastatura.txt");

    //initializare produse
    int n;
    fin >> n;
    vector<Product> products;
    for (int i = 0; i < n; ++i) {
        string name, type;
        float price;
        int stock;
        fin >> name >> price >> stock >> type;
        products.emplace_back(name, price, stock, type);
    }

    //initializare useri
    string first, last, email, role;
    fin >> first >> last >> email >> role;
    User user(first, last, email, role);

    //initializarea shop
    string address;
    fin >> address;
    Shop shop(address, products);

    //initializarea order
    Order order(user, {products[0], products[2]});
    fin.close();

    cout << "=== Shop ===\n" << shop << "\n";
    cout << "=== Order ===\n" << order << "\n";
    cout << "Inventory value: " << shop.calculateInventoryValue() << " RON\n";
    return 0;
}
