#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H
#include <string>
#include <iostream>
class Product {
    static int generalID; // id ul care tine evidenta numarui de obiecte instantiate
    const int ID; // id ul personal al obiectului
    std :: string name;
    float price;
    int stock;

public:
    //constructorul cu toti parametrii
    //const string &name e folosit ca sa nu se mai creeze o copie a stringului,
    //si pentru a nu putea fi folosita adresa ca sa se modifice variabila din clasa
    Product(const std :: string &name, float price, int stock);

    // constructorul de copiere
    Product(const Product &other);
    // destructorul
    virtual ~Product();

    //supraincarcarea operatorului egal
    Product &operator=(const Product &other);

    // reduce stocul
    void reduceStock(int amount);

    //getteri
    float getPrice() const;
    const std :: string &getName() const;
    int getStock() const;
    int getID() const;

    virtual std :: string showDetails() const;
    //supraincarcarea operatorului de afisare
    friend std :: ostream &operator<<(std :: ostream &os, const Product &obj);
};

#endif //OOP_PRODUCT_H