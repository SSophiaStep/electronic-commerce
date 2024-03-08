#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "Store.h"

using namespace std;
void buyProduct(Product product, Product &laptop){
    int buyChoice;
    cout<<"Choose what do you want to purchase :"<<endl;
    cout<<"1. Book"<<endl;
    cout<<"2. Laptop"<<endl;
    cin>>buyChoice;
    int purchaseAmount;
    switch (buyChoice) {
        case(1):{
            cout<<"How much do you wanna buy?"<<endl;
            cin>>purchaseAmount;
            product.SetQuantity(purchaseAmount);
        }break;
        case(2):{
            cout<<"How much do you wanna buy?"<<endl;
            cin>>purchaseAmount;
            product.SetQuantity(purchaseAmount);
        }break;
        default:{
            cout<<"Invalid choice, Try again"<<endl;
        }break;

    }
    cout << "Purchase Amount: " << product.getQuantity() << endl;
    cout << "Product Price: " << product.getPrice()*product.getQuantity() << endl;
}
int main() {

    Customer customer("Nastia", "Goncharova Street", "nastianed@gmail.com");
    Product product("Book", 20.99, 1);
    Product laptop (product);
    laptop.SetItem("laptop");
    Store bazar("Rozetka",{});
    bazar.setStore(product);
    bazar.setStore(laptop);
    //Purchase purchase(1,1);

    int choice;
    cout << "1. Display Customer\n";
    cout << "2. Display Product\n";
    cout << "3. Display Purchase\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: {
                cout<<customer;
            break;
        }
        case 2: {
            bazar.showCatalog();
        }break;
        case 3: {
            buyProduct(product, laptop);
        }break;
        case 0: {
            cout << "Exiting program\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}//laba3