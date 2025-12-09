#include "Shop.h"
#include <iostream>

int Shop::generalID = 1;

Shop::Shop(const std::string &address)
    : ID(generalID++), address(address) {}

//adauga produs
void Shop::addProduct(std::unique_ptr<Product> p) {
    products.push_back(std::move(p));
}

//sterge produs dupa nume
void Shop::removeProductByName(const std::string &name) {
    for (auto it = products.begin(); it != products.end(); ) {
        if ((*it)->getName() == name)
            it = products.erase(it);
        else
            ++it;
    }
}

//calculeaza pretul total al comenzii
float Shop::calculateInventoryValue() const {
    float total = 0;
    for (const auto &p : products)
        total += p->getPrice() * p->getStock();
    return total;
}

void Shop::ProductTypes() const {
    for (auto &p : products) {
        if (auto inst = dynamic_cast<Instrument*>(p.get()))
            std::cout << "Instrument: " << inst->getName() << "\n";
        else if (auto med = dynamic_cast<Media*>(p.get()))
            std::cout << "Media: " << med->getName() << "\n";
        else if (auto book = dynamic_cast<MusicBook*>(p.get()))
            std::cout << "MusicBook: " << book->getName() << "\n";
        else
            std::cout << "Tip necunoscut: " << p->getName() << "\n";
    }
}

std::ostream &operator<<(std::ostream &os, const Shop &obj) {
    os << "Shop ID: " << obj.ID << "\nAddress: " << obj.address << "\nProducts:\n";
    for (const auto &p : obj.products) {
        os << "   " << p->getName() << " (" << p->getType() << ")\n";
    }
    return os;
}
