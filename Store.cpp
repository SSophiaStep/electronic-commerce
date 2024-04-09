#include <string>
#include "Store.h"

Store::Store(string newStoreName, vector<Product> newStore):storeName{newStoreName},store{newStore} {
}

Store::~Store() {

}

void Store::setStore(Product store) {
    this->store.push_back(store);
}

void Store::updateCatalog(const string& filename) {
    ofstream outFile(filename, ios::app);

    if (!outFile.is_open()) {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    string name;
    double price;
    int quantity;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product quantity: ";
    cin >> quantity;

    Product newProduct(name, price, quantity);
    this->store.push_back(newProduct);

    outFile << name << " " << price << " " << quantity << endl;

    outFile.close();
}

void Store::showCatalog()const {
    cout << "============================================================" << endl;
    for (int i = 0; i < this->store.size(); ++i) {
        cout << "Product Item: " << store[i].getItem() << endl;
        cout << "Product Price: " << store[i].getPrice() << endl;
        cout << "Product Quantity: " << store[i].getQuantity() << endl;
        cout << "============================================================" << endl;
    }
}