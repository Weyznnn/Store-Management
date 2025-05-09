#include <iostream>
#include <vector>
#include "market.h"
#include "item.h"
using namespace std;

int main() {
    Market market = Market();
    market.checkStock();
    market.restock("Lemari", 2, 200000);
    market.checkStock();
    return 0;
}