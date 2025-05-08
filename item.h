#include <iostream>
#include <random>
#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item {
    public:
        string name;
        int ID;
        int price;
        int quantity;

    Item(string name, int price, int quantity) {
        Item::name = name;
        Item::ID = createID();
        Item::price = price;
        Item::quantity = quantity;
    }
    
    private:
    int createID() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1000, 9999);
        return distrib(gen);
    }
};
#endif