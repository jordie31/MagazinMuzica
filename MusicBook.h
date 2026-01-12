#ifndef MUSICBOOK_H
#define MUSICBOOK_H

#include "Product.h"

class MusicBook : public Product {
    int numberOfPages;
    std::string author;

public:
    // constructor
    MusicBook(const std::string &name, float price, int stock, int numberOfPages, const std::string &author);

    // destructor
    ~MusicBook() override;

    // getteri
    std::string getType()  ;

    int getNumberOfPages()  ;

     std::string getAuthor()  ;

    // clone
    std::unique_ptr<Product> clone() const ;

    // functia show
    std::string showDetails()  ;

};

#endif // MUSICBOOK_H
