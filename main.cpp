#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Shop.h"
#include "Media.h"
#include "Instrument.h"
#include "MusicBook.h"

int main() {
    std::ifstream fin("tastatura.txt");
    if (!fin) {
        std::cerr << "Nu pot deschide tastatura.txt\n";
        return 1;
    }

    Shop shop("Strada Muzicii 10");

    std::string type;
    while (fin >> type) {
        try {
            if (type == "MEDIA") {
                std::string name, format;
                float price;
                int stock;
                fin >> name >> price >> stock >> format;
                shop.addProduct(std::make_unique<Media>(name, price, stock, format));
            }
            else if (type == "INSTRUMENT") {
                std::string name, material;
                float price;
                int stock;
                fin >> name >> price >> stock >> material;
                shop.addProduct(std::make_unique<Instrument>(name, price, stock, material));
            }
            else if (type == "MUSICBOOK") {
                std::string name, author;
                float price;
                int stock, pages;
                fin >> name >> price >> stock >> pages >> author;
                shop.addProduct(std::make_unique<MusicBook>(name, price, stock, pages, author));
            }
            else {
                std::string rest;
                std::getline(fin, rest);
                std::cerr << "Tip necunoscut: " << type << "\n";
            }
        }
        catch (const std::exception &e) {
            std::cerr << "Eroare produs: " << e.what() << "\n";
        }
    }

    std::cout << "\n=== Shop ===\n" << shop << "\n";
    std::cout << "\n=== Tipuri produse (dynamic_cast) ===\n";
    shop.ProductTypes();

    std::cout << "\nValoarea stocului: " << shop.calculateInventoryValue() << " lei\n";

    return 0;
}
