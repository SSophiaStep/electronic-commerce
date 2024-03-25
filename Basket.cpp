#include "Basket.h"
#include <iostream>

void Basket::AddItem(const Product& product) {
    items.push_back(product);
}

void Basket::RemoveItem(const string& item) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getItem() == item) {
            items.erase(it);
            cout << "Item '" << item << "' removed from basket.\n";
            return;
        }
    }
    cout << "Item '" << item << "' not found in basket.\n";
}

void Basket::ShowItems() {
    cout << "Items in the basket for " << person.getName() << ":" << endl;
    for (const auto& item : items) {
        cout << "- " << item.getItem() << endl;
    }
}
Basket::Basket(const string& person_name, const string& person_address, const string& person_email)
        : person(person_name, person_address, person_email) {
}
Basket::~Basket(){

}