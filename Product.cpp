#include "Product.h"

// instantierea variabilei statice
int Product::generalID = 1;

//constructor princ
Product::Product(const std::string &name, float price, int stock)
    : ID(generalID++)
{
    //exceptii
    if (name.empty())
        throw InvalidNameException(name);
    if (price < 0)
        throw InvalidPriceException(price);
    if (stock < 0)
        throw InvalidStockException(stock);

    this->name = name;
    this->price = price;
    this->stock = stock;
}

//constructor de copiere
Product::Product(const Product &other)
    : ID(generalID++), name(other.name), price(other.price), stock(other.stock) {}

Product::~Product() = default;

// operatorul =
Product &Product::operator=(const Product &other) {
    if (this == &other)
        return *this;

    this->name = other.name;
    this->price = other.price;
    this->stock = other.stock;

    return *this;
}

//reduce stocul
void Product::reduceStock(int amount) {

    //validari
    if (amount <= 0)
        throw ProductException("Eliminarea stocului trebuie facuta cu un numar pozitiv");

    if (amount > stock)
        throw ProductException("Nu este destul stoc pentru a fi eliminat");

    stock -= amount;
}

// getters
float Product::getPrice()  { return price; }
const std::string &Product::getName()  { return name; }
int Product::getStock()  { return stock; }
int Product::getID()  { return ID; }

// functia de show
std::string Product::showDetails()  {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock());
}

// operatorul <<
//std::ostream &operator<<(std::ostream &os, const Product &obj) {
//    return os << obj.showDetails();
//};


