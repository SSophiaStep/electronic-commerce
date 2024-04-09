#ifndef INC_2_STORE_H
#define INC_2_STORE_H
#include "Product.h"
#include <string>
#include <vector>
using namespace std;
class Store {
private:
    string storeName;
    vector<Product> store;
public:
    Store(string newStoreName = "Unknown", vector<Product> newStore = {});
    ~Store();
    void setStore(Product store);
    void updateCatalog(const string& filename);
    void showCatalog()const;

};
#endif//laba2
