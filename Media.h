#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"

class Media : public Product {
    std::string format; // ex: CD, Vinyl, Caseta

public:

    // constructor
    Media(const std::string &name, float price, int stock, const std::string &format);

    // destructor
    ~Media() override;

    // getteri
    std::string getType()  override;

     //std::string& getFormat() ;

    // clone
    std::unique_ptr<Product> clone() const override;

    // functie de show
    std::string showDetails()  override;


};

#endif // MEDIA_H
