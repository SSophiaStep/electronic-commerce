#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;

Product::Product() : item(""), price(0.0), quantity(0) {}

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

string Product::getItem() const {
    return item;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}
void Product::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << item << "\n";
        file << price << "\n";
        file << quantity << "\n";
        file.close();
    } else {
        cout << "Error: Unable to open file for writing\n";
    }
}

void Product::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        getline(file, item);
        file >> price;
        file >> quantity;
        file.close();
    } else {
        cout << "Error: Unable to open file for reading\n";
    }
}

Product::Product(string new_item, double new_price, int new_quantity)
        : item{new_item}, price{new_price}, quantity{new_quantity} {
}
Product::Product(const Product& other):item(other.item), price(other.price), quantity(other.quantity){};

Product::~Product() {
}
//oleg loh