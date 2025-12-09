#ifndef OOP_ORDER_H
#define OOP_ORDER_H

#include <vector>
#include <memory>
#include <iostream>
#include "User.h"
#include "Product.h"

class Order {
    static int generalID;        // id static pentru toate instantele clasei
    const int ID;                // id personal per instanta
    User buyer;                  // userul care face comanda
    std::vector<std::unique_ptr<Product>> products; // vector de pointeri la produse
    float totalPrice = 0;

public:
    // Constructor
    Order(const User &buyer, std::vector<std::unique_ptr<Product>> products);

    // Calcul total
    void calculateTotal();

    // Getter
    float getTotal() const;

    // Afisare
    friend std::ostream &operator<<(std::ostream &os, const Order &obj);
};

#endif // OOP_ORDER_H
