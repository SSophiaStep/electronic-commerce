#include <iostream>
#include "Person.h"
#include "Product.h"
#include "Store.h"
#include "Basket.h"
#include "Customer.h"
#include "OnlineBasket.h"
#include "Admin.h"

using namespace std;
void buyProduct(Product product, Product& laptop, Product& phone) {
    int buyChoice;
    cout << "Choose what do you want to purchase :" << endl;
    cout << "1. Tablet" << endl;
    cout << "2. Laptop" << endl;
    cout << "3. Phone" << endl;
    cin >> buyChoice;
    int purchaseAmount;
    switch (buyChoice) {
        case 1: {
            cout << "How much do you wanna buy?" << endl;
            cin >> purchaseAmount;
            product.SetQuantity(purchaseAmount);
            break;
        }
        case 2: {
            cout << "How much do you wanna buy?" << endl;
            cin >> purchaseAmount;
            laptop.SetQuantity(purchaseAmount);
            break;
        }
        case 3:{
            cout << "How much do you wanna buy?" << endl;
            cin >> purchaseAmount;
            phone.SetQuantity(purchaseAmount);
            break;
        }
        default: {
            cout << "Invalid choice, Try again" << endl;
            break;
        }
    }
    if (buyChoice == 1)
        cout << "Tablet Quantity: " << product.getQuantity() << endl;
    else if (buyChoice == 2)
        cout << "Laptop Quantity: " << laptop.getQuantity() << endl;
    else if (buyChoice == 3)
        cout << "Phone Quantity: " << phone.getQuantity() << endl;

    if (buyChoice == 1)
        cout << "Total Price: " << product.getPrice() * product.getQuantity() << endl;
    else if (buyChoice == 2)
        cout << "Total Price: " << laptop.getPrice() * laptop.getQuantity() << endl;
    else if (buyChoice == 3)
        cout << "Total Price: " << phone.getPrice() * phone.getQuantity() << endl;
}

void viewUserHistory(const Customer& customer) {
    const vector<string>& searchHistory = customer.getSearchHistory();
    cout << "Customer search history:\n";
    for (const string& search : searchHistory) {
        cout << search << endl;
    }
}

void adminMenu() {
    cout << "Admin Menu:\n";
    cout << "1. Display Catalog\n";
    cout << "2. Update Catalog\n";
    cout << "3. View Customer History\n";
    cout << "0. Logout\n";
}

void userMenu() {
    cout << "Welcome to our electronics store!\n";
    cout << "1. Show personal information\n";
    cout << "2. Display Product\n";
    cout << "3. Display Purchase\n";
    cout << "4. Open Basket\n";
    cout << "5. Show Role\n";
    cout << "6. Login as Admin\n";
    cout << "0. Exit\n";
}

int main() {
    Admin admin("oleg", "123321");
    Customer customer("Nastia", "Holovna street", "siarabbit@gmail.com");
    customer.addToSearchHistory("Laptop");
    customer.addToSearchHistory("Phone");
    customer.addToSearchHistory("Tablet");
    Product product("Tablet", 500.99, 1);
    Product laptop("Laptop", 800.99, 1);
    Product phone("Iphone",600.99,1);
    Store bazar("Rozetka", {});
    bazar.setStore(product);
    bazar.setStore(laptop);
    bazar.setStore(phone);
    Basket basket("Nastia", "Holovna Street", "siarabbit@gmail.com", 400.00);
    OnlineBasket *onlineBasket = &basket;
    string filename = "catalog.txt";


    int choice;
    bool isAdminLoggedIn = false;
    while (true) {
        userMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Customer Information:\n";
                cout <<customer;
                break;
            }
            case 2: {
                bazar.showCatalog();
                break;
            }
            case 3: {
                buyProduct(product, laptop,phone);
                break;
            }
            case 4: {
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

                            double minPrice = 400.00;
                            if (newItemPrice < minPrice) {
                                cout << "Error: Incorrect price entered\n";
                                continue;
                            }

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
            case 5: {
                customer.ShowRole();
                break;
            }
            case 6: {
                cout << "Admin Information:\n";
                cout << "Please login with admin credentials.\n";

                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (username == "oleg" && password == "123321") {
                    cout << "Login successful.\n";
                    isAdminLoggedIn = true;
                } else {
                    cout << "Login failed. Incorrect credentials.\n";
                }
                break;
            }
            case 0: {
                cout << "Exiting program.\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

        if (isAdminLoggedIn) {
            while (true) {
                adminMenu();
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        bazar.showCatalog();
                        break;
                    }
                    case 2: {
                        bazar.updateCatalog(filename);
                        break;
                    }
                    case 3: {
                        viewUserHistory(customer);
                        break;
                    }
                    case 0: {
                        isAdminLoggedIn = false;
                        cout << "Logging out...\n";
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }

                if (!isAdminLoggedIn || choice == 0) {
                    break;
                }
            }
        }
    }
    return 0;
}