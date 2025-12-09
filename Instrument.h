#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "Product.h"

class Instrument : public Product {
    std::string material;  // ex: Lemn, Metal, Plastic

public:
    // Constructor corect (include material)
    Instrument(const std::string &name, float price, int stock, const std::string &material);

    // Destructor
    ~Instrument() override;

    // Tipul produsului
    std::string getType() const override {
        return "Instrument";
    }

    // Copiere polimorfa
    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Instrument>(*this);
    }

    // Detalii specifice
    std::string showDetails() const override;

    // getter optional
    const std::string& getMaterial() const { return material; }
};

#endif // INSTRUMENT_H
