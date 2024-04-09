#ifndef INC_2_PRODUCT_H
#define INC_2_PRODUCT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Product{
private:
    string item;
    double price;
    int quantity;
public:
    void SetItem(string new_item);
    void SetPrice(double new_price);
    void SetQuantity(int new_quantity);
    string getItem() const;
    double getPrice() const;
    int getQuantity() const;
    Product();
    Product(string new_item);
    Product(string new_item,double new_price);
    Product(string new_item, double new_price, int new_quantity);
    Product(const Product& other);
    ~Product();
};


#endif