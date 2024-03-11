#ifndef INC_2_BASKET_H
#define INC_2_BASKET_H
#include <iostream>
#include "Customer.h"
#include <vector>
using namespace std;

class Basket:public Customer{
private:
    vector<string> items;
public:
    void AddItem(const string& item);
    void RemoveItem(const string& item);
    void ShowItems();
    Basket(const Basket& other);
    Basket(const string& customer_name, const string& customer_address, const string& customer_email);
    ~Basket();
};

#endif//basket
