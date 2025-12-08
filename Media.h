#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"

class Media : public Product {
    std :: string format; // ex: CD, Vinyl, Caseta
public:
    Media (const std :: string &name, float price, int stock, const std :: string &format);

    std :: string showDetails() const;

    ~Media();
};

#endif //MEDIA_H
