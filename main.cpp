#include <iostream>
#include <fstream>
#include "Person.h"
#include "Product.h"
#include "Store.h"
#include "Basket.h"
#include "Customer.h"
#include "OnlineBasket.h"
#include "Admin.h"

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
            laptop.SetQuantity(purchaseAmount);
        }break;
        default:{
            cout<<"Invalid choice, Try again"<<endl;
        }break;
    }
    cout << "Purchase Amount: " << product.getQuantity() << endl;
    if(buyChoice == 1)
        cout << product.getQuantity() << endl;
    else
        cout << laptop.getQuantity() << endl;
    cout << "Product Price: " ;
    if(buyChoice == 1)
        cout << product.getPrice()*product.getQuantity() << endl;
    else
        cout << laptop.getPrice()*laptop.getQuantity() << endl;
}
int main() {
    Person person("Nastia", "Holovna Street", "siarabbit@gmail.com");
    Customer customer("Oleg", "Selo Shypyntsi", "oishidemon@gmail.com");
    Product product("Book", 20.99, 2);
    product.saveToFile("product_data.txt");
    Product newProduct;
    newProduct.loadFromFile("product_data.txt");
    Product laptop(product);
    laptop.SetItem("laptop");
    laptop.SetPrice(300.99);
    laptop.SetQuantity(2);
    laptop.saveToFile("laptop_data.txt");
    laptop.loadFromFile("laptop_data.txt");
    Store bazar("Rozetka", {});
    bazar.setStore(product);
    bazar.setStore(laptop);
    Basket basket("Nastia", "Holovna Street", "siarabbit@gmail.com");
    OnlineBasket *onlineBasket = &basket;
    Admin admin("oleg", "123321");


    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "Choose role:\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Admin Information:\n";
                cout << "Please login with admin credentials.\n";

                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (username == "oleg" && password == "123321") {
                    cout << "Login successful.\n";
                    admin.displayCatalog(bazar);
                } else {
                    cout << "Login failed. Incorrect credentials.\n";
                    continue;
                }
                break;
            }
            case 2: {
                cout << "Customer Information:\n";
                cout << person;
                customer.AddRole("Customer");
                break;
            }
            case 0: {
                exitProgram = true;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
        if (exitProgram) {
            break;
        }

        if (choice == 2) {
            while (true) {
                cout << "1. Open Basket\n";
                cout << "2. Display Product\n";
                cout << "3. Display Purchase\n";
                cout << "4. Show Role\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Opening Basket...\n";
                        bool backToMenu = false;
                        while (!backToMenu) {
                            onlineBasket->ShowItems();
                            cout << "1. Add Item to Basket\n";
                            cout << "2. Remove Item from Basket\n";
                            cout << "0. Back to Main Menu\n";
                            cout << "Enter your choice: ";
                            int basketChoice;
                            cin >> basketChoice;
                            switch (basketChoice) {
                                case 1: {
                                    string newItemName;
                                    double newItemPrice;
                                    int newItemQuantity;
                                    cout << "Enter item name: ";
                                    cin >> newItemName;
                                    cout << "Enter item price: ";
                                    cin >> newItemPrice;
                                    cout << "Enter item quantity: ";
                                    cin >> newItemQuantity;
                                    Product newItem(newItemName, newItemPrice, newItemQuantity);
                                    onlineBasket->AddItem(newItem);
                                    cout << "Item added to basket.\n";
                                    break;
                                }
                                case 2: {
                                    string removeItemName;
                                    cout << "Enter item name to remove: ";
                                    cin >> removeItemName;
                                    onlineBasket->RemoveItem(removeItemName);
                                    cout << "Item removed from basket.\n";
                                    break;
                                }
                                case 0: {
                                    backToMenu = true;
                                    break;
                                }
                                default: {
                                    cout << "Invalid choice. Please try again.\n";
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case 2: {
                        bazar.showCatalog();
                        break;
                    }
                    case 3: {
                        buyProduct(product, laptop);
                        break;
                    }
                    case 4: {
                        cout << "Current Role\n";
                        customer.ShowRole();
                        break;
                    }
                    case 0: {
                        cout << "Exiting program\n";
                        exitProgram = true;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
                if (exitProgram || choice == 0) {
                    break;
                }
            }
        }
    }
}