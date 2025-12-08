#include "Media.h"

Media :: Media (const std :: string &name, float price, int stock, const std :: string &format)
        : Product(name, price, stock), format(format) {};

std :: string Media :: showDetails() const{
    return "ID: " + std :: to_string(this -> getID()) +
            + " | Name: " + this -> getName() +
                + " | Price: " + std :: to_string(this -> getPrice()) +
                    + " | Stock: " + std :: to_string(this -> getStock()) +
                        + " | Format: " + this -> format;
}

Media :: ~Media() = default;