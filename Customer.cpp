#include "Customer.h"
#include "Person.h"
#include <iostream>
#include <vector>
using namespace std;

void Customer::AddRole(const string &role) {
    roles.push_back(role);
}
void Customer::ShowRole()const{
    cout << "Roles: ";
    for (const auto& role : roles) {
        cout << role << ", ";
    }
    cout << endl;
}
Customer::Customer(const string& person_name, const string& person_address, const string& person_email)
        : Person(person_name, person_address, person_email) {}

Customer::Customer(const Customer& other) : Person(other) {
    roles = other.roles;
}

Customer::~Customer() {

}