#include "MusicBook.h"

    MusicBook :: MusicBook (const std :: string &name, float price, int stock, int numberOfPages, const std :: string &author)
        : Product(name, price, stock), numberOfPages(numberOfPages), author(author) {};

    std::string MusicBook :: showDetails() const{
        return "ID: " + std :: to_string(this -> getID()) +
            + " | Name: " + this -> getName() +
    + " | Author: " + this -> author +
        + " | Number of Pages: " + std :: to_string(this -> numberOfPages) +
                + " | Price: " + std :: to_string(this -> getPrice()) +
                    + " | Stock: " + std :: to_string(this -> getStock());

    }

MusicBook :: ~MusicBook() = default;