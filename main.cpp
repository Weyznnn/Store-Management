#include <iostream>
#include <vector>
#include "market.h"
#include "item.h"
using namespace std;

int main() {
    vector<Item> item1 = {Item("Beras 5kg", 65000, 10), 
                           Item("Gula 1kg", 15000, 20),
                           Item("Minyak Goreng 1 Liter", 20000, 15),
                           Item("Telur Ayam 1kg", 25000, 5),
                           Item("Daging Sapi 1kg", 120000, 8)};
    Market market = Market(item1);
    market.checkStock();
    market.sell("Gula 1kg", 3);
    market.sell("Minyak Goreng 1 Liter", 5);
    market.restock("Daging Sapi 1kg", 5);
    return 0;
}