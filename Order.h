#ifndef OOP_ORDER_H
#define OOP_ORDER_H
#include <vector>
#include <iostream>
#include "User.h"
#include "Product.h"
#include "Logger.h"

class Order {
    static int generalID; // id static pentru toate instantele clasei
    const int ID; // id personal per instanta
    User buyer;    // userul care face comanda
    std :: vector<Product*> products; // vecotr de produse
    float totalPrice = 0;
    static Logger logger;
public:
    //constructor cu toti parametrii
    Order(const User &buyer, const std :: vector<Product*> products);
    // calculeaza pretul total al produselor din comanda
    void calculateTotal();
    //int getID();
    // getter
    //float getTotal() const;

    // observer pentur logging
    void onAddProduct(Product *product);


    // supraincarcarea operatorului de afisare
    friend std :: ostream &operator<<(std :: ostream &os, const Order &obj);
};
#endif //OOP_ORDER_H