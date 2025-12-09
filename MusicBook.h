#ifndef MUSICBOOK_H
#define MUSICBOOK_H

#include "Product.h"

class MusicBook : public Product {
    int numberOfPages;
    std::string author;

public:
    //constructor
    MusicBook(const std::string &name, float price, int stock, int numberOfPages, const std::string &author);

    ~MusicBook() override;

    std::string getType() const override {
        return "MusicBook";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<MusicBook>(*this);
    }

    std::string showDetails() const override;

    //getteri
    int getNumberOfPages() const { return numberOfPages; }
    const std::string& getAuthor() const { return author; }
};

#endif // MUSICBOOK_H
