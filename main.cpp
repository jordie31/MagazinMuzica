#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "User.h"
#include "Product.h"
#include "Shop.h"
#include "Order.h"
#include "Media.h"
#include "MusicBook.h"
#include "Instrument.h"
using namespace std;

int main() {


    Media test ("Album1", 59.99, 10, "Vinyl");
    cout << test.showDetails() << endl;

    MusicBook test2 ("Music Theory", 39.99, 5, 250, "John Doe");
    cout << test2.showDetails() << endl;

    Instrument test3 ("Guitar", 199.99, 3, "Wood");
    cout << test3.showDetails() << endl;

    vector < Product  > vecProdus;
    vecProdus.push_back(test3);
    vecProdus.push_back(test2);
    vecProdus.push_back(test);

    Shop shop1 ("123 Music St", vecProdus);
    cout << shop1;
    return 0;
}
