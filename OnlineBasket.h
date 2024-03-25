#ifndef ONLINEBASKET_H
#define ONLINEBASKET_H

#include "Product.h"
#include <string>

class OnlineBasket {
public:
    virtual void AddItem(const Product& product) = 0;
    virtual void RemoveItem(const std::string& item) = 0;
    virtual void ShowItems() = 0;
    virtual ~OnlineBasket() {}
};

#endif