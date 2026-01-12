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
    std::string getType()  override;

    //int getNumberOfPages()  ;

     //std::string getAuthor()  ;

    // clone
    std::unique_ptr<Product> clone() const override;

    // functia show
    std::string showDetails() override ;

};

#endif // MUSICBOOK_H
