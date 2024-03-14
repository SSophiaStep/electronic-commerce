#ifndef INC_2_PERSON_H
#define INC_2_PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person{
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
    friend ostream& operator<<(ostream &os, const Person& person);
    Person();
    Person(string new_name);
    Person(string new_name, string new_address);
    Person(string new_name, string new_address, string new_email);
    ~Person();
};
#endif