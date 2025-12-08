#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include "Product.h"


class Instrument : public Product{
    std :: string material;
public:
    Instrument (const std :: string &name, float price, int stock, const std :: string &material);

    std :: string showDetails() const;

    ~Instrument();

};



#endif //INSTRUMENT_H
