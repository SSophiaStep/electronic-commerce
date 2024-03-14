#include "Person.h"
#include <iostream>
using namespace std;

void Person::SetName(string new_name) {
    name=new_name;
}
void Person::SetAddress(string new_address) {
    address=new_address;
}
void Person::SetEmail(string new_email) {
    email = new_email;
}
string Person::getName() {
    return name;
}
string Person::getAddress() {
    return address;
}
string Person::getEmail() {
    return email;
}

ostream &operator<<(ostream &os, const Person &person) {
    os <<"----------------------------------------------"<<endl;
    os << "Person Name: " << person.name << endl;
    os << "Person Email: " << person.email << endl;
    os << "Person Address: " << person.address << endl;
    os <<"----------------------------------------------"<<endl;

    return os;
}
Person::~Person() {
}
Person::Person(string new_name, string new_address, string new_email)
        :name{new_name},address{new_address},email{new_email} {
}
//laba1