#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "Purchase.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "1. Display Customer\n";
        cout << "2. Display Product\n";
        cout << "3. Display Purchase\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Customer customer("Nastia", "Goncharova Street", "nastianed@gmail.com");
                cout << "Customer Name: " << customer.getName() << endl;
                cout << "Customer Email: " << customer.getEmail() << endl;
                cout << "Customer Address: " << customer.getAddress() << endl;
                break;
            }
            case 2: {
                Product product("Book", 20.99, 1);
                cout << "Product Item: " << product.getItem() << endl;
                cout << "Product Price: " << product.getPrice() << endl;
                cout << "Product Quantity: " << product.getQuantity() << endl;
                break;
            }
            case 3: {
                Purchase purchase(41.98, 2);
                cout << "Purchase Amount: " << purchase.getAmount() << endl;
                cout << "Product Price: " << purchase.getProductPrice() << endl;
                break;
            }
            case 0: {
                cout << "Exiting program\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while(choice != 0);

    return 0;
}
