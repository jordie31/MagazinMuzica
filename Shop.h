//
// Created by Irina on 12/6/2025.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H
#include <string>
#include <vector>
#include "Product.h"

class Shop {
    static int generalID; // id static pentru generarea id urilor instantelor
    const int ID; // id ul personal al instantelor
    std :: string address;
    std :: vector<Product> products; // vector de produse
public:
    //constructorul cu toti parametrii
    Shop(const std :: string &address, const std :: vector<Product> &products)
        : ID(generalID++), address(address), products(products) {}


    // const product &p = o referinta la un produs p care este constanta, pentru a nu putea fi modificata ( vreau doar sa adaug, fara sa duplic)
    void addProduct(const Product &p) { products.push_back(p); }

    //stergerea unui produs dupa nume din magazin
    void removeProductByName(const std :: string &name) {
        for (auto it = products.begin(); it != products.end(); ) { // parcurg vectorul de produse
            if (it->getName() == name) { // daca numele produsului la care am ajuns este numele produsului pe care vreau sa il sterg
                it = products.erase(it); // sterg produsul
            } else {
                ++it; // trec la urmatorul
            }
        }
    }

    // calculez pretul tuturor produselor din magazin
    float calculateInventoryValue() const {
        float total = 0;
        for (const auto &p : products)
            total += p.getPrice() * p.getStock();
        return total;
    }
    //supraincarcarea operatorului de afisare
    friend ostream &operator<<(ostream &os, const Shop &obj) {
        os << "Shop ID: " << obj.ID << "\nAddress: " << obj.address << "\nProducts:\n";
        for (const auto &p : obj.products) os << "   " << p << "\n";
        return os;
    }
};
//initializarea variabilei statice
int Shop::generalID = 1;



#endif //OOP_SHOP_H