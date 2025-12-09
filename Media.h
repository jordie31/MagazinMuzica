#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"

class Media : public Product {
    std::string format; // ex: CD, Vinyl, Caseta

public:
    Media(const std::string &name, float price, int stock, const std::string &format);

    ~Media() override;

    std::string getType() const override {
        return "Media";
    }

    std::unique_ptr<Product> clone() const override {
        return std::make_unique<Media>(*this);
    }

    std::string showDetails() const override;

    // Dacă ai nevoie să accesezi formatul:
    const std::string& getFormat() const { return format; }
};

#endif // MEDIA_H
