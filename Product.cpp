#include "Product.h"

    //constructorul cu toti parametrii
    //const string &name e folosit ca sa nu se mai creeze o copie a stringului,
    //si pentru a nu putea fi folosita adresa ca sa se modifice variabila din clasa
    Product :: Product(const std :: string &name, float price, int stock)
        : ID(generalID++), name(name), price(price), stock(stock) {}

    // constructorul de copiere
    Product :: Product(const Product &other)
        : ID(generalID++), name(other.name), price(other.price), stock(other.stock) {}

    // destructorul
    Product :: ~Product() = default;

    //supraincarcarea operatorului egal
    Product & Product :: operator =(const Product &other) {
        if (this == &other) return *this;
        name = other.name;
        price = other.price;
        stock = other.stock;
        return *this;
    }

    // reduce stocul
    void Product :: reduceStock(int amount) {
        if (amount > stock) amount = stock;
        stock -= amount;
    }

    //getteri
    float Product :: getPrice() const { return price; }
    const std :: string & Product :: getName() const { return name; }
    int Product :: getStock() const { return stock; }
    int Product :: getID() const { return ID; }

    std :: string Product :: showDetails() const{
        return "ID: " + std :: to_string(this -> getID()) +
            + " | Name: " + this -> getName() +
                + " | Price: " + std :: to_string(this -> getPrice()) +
                    + " | Stock: " + std :: to_string(this -> getStock()) ;
    }

    //supraincarcarea operatorului de afisare
std :: ostream & operator<<(std :: ostream &os, const Product &obj) {
        return os << obj.showDetails();
    }

//instantierea variabilei statice
int Product::generalID = 1;