#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <memory>
#include "Product.h"
#include "Instrument.h"
#include "MusicBook.h"
#include "Media.h"

class Factory{

// functiile creeaza obiecte de tip produs, cu parametrii specifici pentru fiecare tip de copil al produsului
// si returneaza un pointer de tip produs
public :
    static std::unique_ptr<Product> createInstrument(
                        const std::string &name, float price, int stock, const std::string &material);

    static std::unique_ptr<Product> createMedia(
                        const std::string &name, float price, int stock, const std::string &format);

    static std::unique_ptr<Product> createMusicBook(
                        const std::string &name, float price, int stock, int numberOfPages, const std::string &author);
};


#endif