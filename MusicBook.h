#ifndef MUSICBOOK_H
#define MUSICBOOK_H
#include "Product.h"

class MusicBook : public Product{
    int numberOfPages;
    std :: string author;
public:
    MusicBook (const std :: string &name, float price, int stock, int numberOfPages, const std :: string &author);
    ~MusicBook();

    std::string showDetails() const;
};


#endif //MUSICBOOK_H