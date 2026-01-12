#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H
#include <string>
#include <iostream>
#include <memory>
#include "ProductExceptions.h"


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
    float getPrice() ;
    const std :: string &getName() ;
    int getStock() ;
    int getID() ;

    //functii virtuale pt polimorfism
    //returnează tipul obiectului (ex: Instrument, Media, MusicBook)
    virtual std::string getType()  = 0;

    //afișare detalii virtuala
     virtual std::string showDetails() ;


    //supraincarcarea operatorului de afisare
//    friend std :: ostream &operator<<(std :: ostream &os,  Product &obj);

    // declararea virtuala ca sa mearga clasele derivate
     virtual std::unique_ptr<Product> clone() const = 0;
};

#endif //OOP_PRODUCT_H