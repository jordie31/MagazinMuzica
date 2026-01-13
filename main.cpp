#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Shop.h"
#include "Media.h"
#include "Instrument.h"
#include "MusicBook.h"
#include "Factory.h"
#include "Logger.h"
#include "User.h"
#include "Product.h"
#include "Order.h"
Logger logger("log.txt");
int main() {

    //logger.log("Text");
    std::ifstream fin("tastatura.txt");
    if (!fin) {
        std::cerr << "Nu pot deschide fisierul tastatura.txt\n";
        return 1;
    }
    Shop shop("Strada Muzicii 10");
    Shop shop2("Bulevardul Cantecului 5");


    std::string type;
    while (fin >> type) {
        try {
            if (type == "MEDIA") {
                std::string name, format;
                float price;
                int stock;
                fin >> name >> price >> stock >> format;
                shop.addProduct(Factory :: createMedia(name, price, stock, format));
            }
            else if (type == "INSTRUMENT") {
                std::string name, material;
                float price;
                int stock;
                fin >> name >> price >> stock >> material;
                shop2.addProduct(Factory :: createInstrument(name, price, stock, material));
            }
            else if (type == "MUSICBOOK") {
                std::string name, author;
                float price;
                int stock, pages;
                fin >> name >> price >> stock >> pages >> author;
                shop.addProduct(Factory :: createMusicBook(name, price, stock, pages, author));
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



    int exit = 0;
    while(exit!=1){
        std :: cout << "\nBine ati venit!" << std :: endl;
        std :: string firstName;
        std :: cout << "Introduceti numele: "; std :: cin >> firstName;
        std :: string lastName;
        std :: cout << "Introduceti prenumele: "; std :: cin >> lastName;
        std :: string email;
        std :: cout << "Introduceti email-ul: "; std :: cin >> email;
        std :: string role = "cumparator";

        User user(firstName, lastName, email, role);

        std :: cout << user;
        int exit2 = 0;
        while(exit2!=1){
            std :: cout << "\nAlegeti shopul" << std :: endl;
            std :: cout << "1) " << shop.getAddress() << std :: endl;
            std :: cout << "2) " << shop2.getAddress() << std :: endl;
            // mai multe optiuni
            int optiune, optiune2;
            std :: cin >> optiune;
            std :: vector<Product*> finalProducts;
            switch (optiune){
                case 1:
                while(true){
                    std :: cout << "Magazinul 1" << std::endl;
                    std :: cout << "Stocul magazinului: "<< std::endl;
                    std :: cout << shop << "\n";
                    std :: cout << "Ce produse doriti sa adaugati in cos? "<< std::endl;

                    const std::vector<std::unique_ptr<Product>>& productList = shop.getProducts();
                    for (int i = 0; i < shop.getProductsLenght(); i++) {
                        std :: cout << i + 1 << ")" << productList[i]->getName() << " "
                             << productList[i]->getPrice() << " lei" << "............ In Stoc: "
                             << productList[i]->getStock() << std :: endl;
                    }

                    std :: cout << "0) Confirmare" << std::endl;
                    std :: cin>>optiune2;
                    optiune2--;

                    if(optiune2==-1){
                        Order orderFinal (user, finalProducts);
                        std :: cout<< orderFinal << std :: endl;
                        std :: cout << "Multumim, va mai asteptam!" << std :: endl;
                        return 0;
                    }
                    else {
                        if(optiune2<shop.getProductsLenght()){
                            finalProducts.push_back(shop.getProduct(optiune2));
                        }
                    }
                }
                case 2:
                while(true){
                    std :: cout << "Magazinul 2" << std::endl;
                    std :: cout << "Stocul magazinului: "<< std::endl;
                    std :: cout << shop2 << "\n";
                    std :: cout << "Ce produse doriti sa adaugati in cos? "<< std::endl;

                    const std::vector<std::unique_ptr<Product>>& productList = shop2.getProducts();
                    for (int i = 0; i < shop2.getProductsLenght(); i++) {
                        std :: cout << i + 1 << ")" << productList[i]->getName() <<" "
                             << productList[i]->getPrice() << " lei" << "............ In Stoc: "
                             << productList[i]->getStock() << std :: endl;
                    }
                    std :: cout << "0) Confirmare" << std::endl;
                    std :: cin>>optiune2;
                    optiune2--;

                    if(optiune2==-1){
                        Order orderFinal (user, finalProducts);
                        std :: cout<< orderFinal << std :: endl;
                        std :: cout << "Multumim, va mai asteptam!" << std :: endl;
                        return 0;
                    }
                    else {
                        if(optiune2<shop2.getProductsLenght()){
                            finalProducts.push_back(shop2.getProduct(optiune2));
                        }
                    }
                }
                default:
                    break;
            }
        }

        break;
    }


    return 0;
}
