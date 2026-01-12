#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "Product.h"

class Instrument : public Product {
    std::string material;  // ex: Lemn, Metal, Plastic

public:
    // constructor
    Instrument(const std::string &name, float price, int stock, const std::string &material);

    // destructor
    ~Instrument() override;

    // tipul produsului
    std::string getType() override;

    // copiere polimorfa
    std::unique_ptr<Product> clone() const override;

    // detalii specifice
    std::string showDetails()  override;

    // getter optional
     //std::string& getMaterial() ;
};

#endif // INSTRUMENT_H
