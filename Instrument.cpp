#include "Instrument.h"

Instrument :: Instrument (const std :: string &name, float price, int stock, const std :: string &material)
    : Product(name, price, stock), material(material) {};

Instrument :: ~Instrument() = default;

std :: string Instrument :: showDetails() const{
    return "ID: " + std :: to_string(this -> getID()) +
        + " | Name: " + this -> getName() +
+ " | Material: " + this -> material +
            + " | Price: " + std :: to_string(this -> getPrice()) +
                + " | Stock: " + std :: to_string(this -> getStock()) ;
}