#include "Order.h"

// Initializare id static
int Order::generalID = 1;

// Constructor
Order::Order(const User &buyer, std::vector<std::unique_ptr<Product>> products)
    : ID(generalID++), buyer(buyer)
{
    // Mut pointerii in vectorul comenzii
    for (auto &p : products)
        this->products.push_back(std::move(p));

    calculateTotal();
}

// Calculeaza totalul
void Order::calculateTotal() {
    totalPrice = 0;
    for (const auto &p : products)
        totalPrice += p->getPrice() * p->getStock(); // poti ajusta dupa nevoie (ex: cantitate)
}

// Getter total
float Order::getTotal() const { return totalPrice; }

// Afisare comanda
std::ostream &operator<<(std::ostream &os, const Order &obj) {
    os << "Order ID: " << obj.ID << "\nBuyer: " << obj.buyer << "\nProducts:\n";
    for (const auto &p : obj.products)
        os << "   " << p->showDetails() << "\n";
    os << "Total price: " << obj.totalPrice << "\n";
    return os;
}
