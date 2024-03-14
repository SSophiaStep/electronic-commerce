#ifndef INC_2_CUSTOMER_H
#define INC_2_CUSTOMER_H
#include "Person.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Customer:public Person{
private:
    vector<string> roles;

public:
    void AddRole(const string& role);
    void ShowRole()const;
    Customer(const Customer& other);
    Customer(const string& person_name, const string& person_address, const string& person_email);
    ~Customer();

};
#endif