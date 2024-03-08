#include "Product.h"
#include <iostream>
using namespace std;

void Product::SetItem(string new_item) {
    item = new_item;
}

void Product::SetPrice(double new_price) {
    if (new_price >= 0.0) {
        price = new_price;
    } else {
        cout << "Error: Price cannot be negative\n";
    }
}

void Product::SetQuantity(int new_quantity) {
    quantity = new_quantity;
}

string Product::getItem() {
    return item;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

Product::Product(string new_item, double new_price, int new_quantity)
        : item{new_item}, price{new_price}, quantity{new_quantity} {
}
Product::Product(const Product& other):item(other.item), price(other.price), quantity(other.quantity){};

Product::~Product() {
}
//oleg loh