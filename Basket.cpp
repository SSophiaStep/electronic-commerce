#include "Basket.h"
#include "Person.h"
#include <vector>
#include <iostream>
using namespace std;
void Basket::AddItem(const string& item) {
    items.push_back(item);
}
void Basket::ShowItems() {
    cout<<"============================================================"<<endl;
    cout << "Items in the basket for " << ":" << endl;
    for (const auto& item : items) {
        cout << "- " << item << endl;
        cout<<"============================================================"<<endl;
    }
}

Basket::Basket(const string& person_name, const string& person_address, const string& person_email)
        : person(person_name, person_address, person_email), items() {}

Basket::~Basket() {}//basket