#ifndef INC_2_BASKET_H_
#define INC_2_BASKET_H_

#include <iostream>
#include "OnlineBasket.h"
#include "Person.h"
#include <vector>
using namespace std;
class Basket : public OnlineBasket {
private:
    vector<Product> items;
    Person person;

public:
    void AddItem(const Product& product) override;
    void RemoveItem(const string& item) override;
    void ShowItems() override;
    Basket(const string& person_name, const string& person_address, const string& person_email);
    virtual ~Basket();
};

#endif