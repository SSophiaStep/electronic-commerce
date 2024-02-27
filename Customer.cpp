#include "Customer.h"
#include <iostream>
using namespace std;

void Customer::SetName(string new_name) {
    name=new_name;
}
void Customer::SetAddress(string new_address) {
    address=new_address;
}
void Customer::SetEmail(string new_email) {
        email = new_email;
    }
    string Customer::getName() {
        return name;
}
    string Customer::getAddress() {
        return address;
}
string Customer::getEmail() {
    return email;
}

Customer::~Customer() {
}
Customer::Customer(string new_name,string new_address,string new_email):name{new_name},address{new_address},email{new_email}{

}

