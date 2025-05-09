#include "item.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#ifndef MARKET_H
#define MARKET_H

string createTable(string item, int collumLenght) {
    string space = "";
    if(item.length() > collumLenght) {
        item = item.substr(0, collumLenght - 3) + "...";
    }
    for(int i = item.length(); i < collumLenght; i++) {
        space += " ";
    }
    return item + space;
}

class Market {
    private:
        vector<Item> stock;
        
    public: Market(vector<Item>stock) {
            Market::stock = stock;
        }

        void checkStock() {
            cout << "+------+-----------------+----------+----------+" << endl
            <<      "| Id   | Product name    | Price    | Quantity |" << endl
            <<      "+------+-----------------+----------+----------+" << endl;
            for(int i = 0; i < stock.size(); i++) {
                cout << "| " << stock[i].ID << " | "
                << createTable(stock[i].name, 16) << "| "
                << createTable(to_string(stock[i].price), 9) << "| "
                << createTable(to_string(stock[i].quantity), 9) << "|" << endl
                <<  "+------+-----------------+----------+----------+" << endl;
            }
        }
        
        void sell(string name,int amount) {
            for(int i = 0; i < stock.size(); i++) {
                if(name == stock[i].name) {
                    if(stock[i].quantity < amount) {
                        cout << "Stock not enough" << endl;
                        return;
                    } else{
                        stock[i].quantity - amount;
                        cout << stock[i].name << " has been sell: " << amount << endl
                        << "Total harga: " << stock[i].price * amount << endl;
                        return;
                    }
                }
            }
            cout << "Please enter right product name!" << endl;
        }

        void restock(string name,int amount) {
            for(int i = 0; i < stock.size(); i++) {
                if(name == stock[i].name) {
                    stock[i].quantity + amount;
                    cout << stock[i].name << " succesfull restocked: " << amount << endl
                    << "Total stock on " << stock[i].name << " : " << stock[i].quantity << endl;
                    return;
                }
            }
            cout << "Please enter right product name!" << endl;
        }
};
#endif