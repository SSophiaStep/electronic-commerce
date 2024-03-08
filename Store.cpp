#include <string>
#include "Store.h"

Store::Store(string newStoreName, vector<Product> newStore):storeName{newStoreName},store{newStore} {
}

Store::~Store() {

}

void Store::setStore(Product store) {
    this->store.push_back(store);
}
void Store::showCatalog() {
    cout<<"============================================================"<<endl;
    for (int i = 0; i < this->store.size(); ++i) {
        cout << "Product Item: " << store[i].getItem() << endl;
        cout << "Product Price: " << store[i].getPrice() << endl;
        cout << "Product Quantity: " << store[i].getQuantity() << endl;
        cout<<"============================================================"<<endl;
    }
}
//laba2
