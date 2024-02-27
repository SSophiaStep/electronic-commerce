#ifndef INC_2_COSTUMER_H
#define INC_2_COSTUMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer{
private:
    string name;
    string address;
    string email;
public:
    void SetName(string new_name);
    void SetAddress(string new_address);
    void SetEmail(string new_email);
    string getName();
    string getAddress();
    string getEmail();
    Customer();
    Customer(string new_name);
    Customer(string new_name, string new_address);
    Customer(string new_name, string new_address, string new_email);
    ~Customer();
};

#endif


