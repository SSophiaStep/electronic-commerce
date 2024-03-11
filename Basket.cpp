#include "Basket.h"
#include "Customer.h"
#include <vector>
#include <iostream>
using namespace std;
void Basket::AddItem(const string& item) {
    items.push_back(item);
}

void Basket::RemoveItem(const string& item) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i] == item) {
            items.erase(items.begin() + i);
            return;
        }
    }
}
void Basket::ShowItems() {
    cout << "Items in the basket for " << getName() << ":" << endl;
    for (const auto& item : items) {
        cout << "- " << item << endl;
    }
}

Basket::Basket(const string& customer_name, const string& customer_address, const string& customer_email)
        : Customer(customer_name, customer_address, customer_email), items() {}

Basket::~Basket() {}//basket