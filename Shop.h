#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Product.h"
#include "Instrument.h"
#include "Media.h"
#include "MusicBook.h"

class Shop {
    static int generalID;
    const int ID;
    std::string address;

    std::vector<std::unique_ptr<Product>> products;

public:
    Shop(const std::string &address);

    void addProduct(std::unique_ptr<Product> p);
    //void removeProductByName(const std::string &name);

    float calculateInventoryValue() const;
    void ProductTypes() const;

    friend std::ostream &operator<<(std::ostream &os, const Shop &obj);
};

#endif
