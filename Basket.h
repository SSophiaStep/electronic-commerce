#ifndef INC_2_BASKET_H
#define INC_2_BASKET_H
#include <iostream>
#include "Person.h"
#include <vector>
using namespace std;

class Basket{
private:
    vector<string> items;
    Person person;
public:
    void AddItem(const string& item);
    void ShowItems();
    Basket(const Basket& other);
    Basket(const string& person_name, const string& person_address, const string& person_email);
    ~Basket();
};

#endif//basket
