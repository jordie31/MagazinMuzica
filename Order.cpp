#include "Order.h"

//constructor cu toti parametrii
Order :: Order(const User &buyer, const std :: vector<Product> &products)
    : ID(generalID++), buyer(buyer), products(products) {
    calculateTotal();
}
// calculeaza pretul total al produselor din comanda
void Order :: calculateTotal() {
    totalPrice = 0;
    // parcurgerea vectorului de produse si adaugarea pretului fiecarui produs la suma totala
    for (const auto &p : products)
        totalPrice += p.getPrice();

}
// getter
float Order :: getTotal() const { return totalPrice; }

// supraincarcarea operatorului de afisare
std ::  ostream & operator<<(std :: ostream &os, const Order &obj) {
    os << "Order ID: " << obj.ID << "\nBuyer: " << obj.buyer << "\nProducts:\n";
    for (const auto &p : obj.products) os << "   " << p << "\n";
    os << "Total price: " << obj.totalPrice << "\n";
    return os;
}
//instantierea variabilei statice
int Order::generalID = 1;