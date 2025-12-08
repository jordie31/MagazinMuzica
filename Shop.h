#ifndef OOP_SHOP_H
#define OOP_SHOP_H
#include <string>
#include <vector>
#include "Product.h"
#include <iostream>

class Shop {
    static int generalID; // id static pentru generarea id urilor instantelor
    const int ID; // id ul personal al instantelor
    std :: string address;
    std :: vector<Product> products; // vector de produse
public:
    //constructorul cu toti parametrii
    Shop(const std :: string &address, const std :: vector<Product> &products);


    // const product &p = o referinta la un produs p care este constanta, pentru a nu putea fi modificata ( vreau doar sa adaug, fara sa duplic)
    void addProduct(const Product &p);

    //stergerea unui produs dupa nume din magazin
    void removeProductByName(const std :: string &name);

    // calculez pretul tuturor produselor din magazin
    float calculateInventoryValue() const;
    //supraincarcarea operatorului de afisare
    friend std :: ostream &operator<<(std :: ostream &os, const Shop &obj);
};


#endif //OOP_SHOP_H