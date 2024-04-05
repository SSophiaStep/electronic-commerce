#ifndef INC_2_ADMIN_H
#define INC_2_ADMIN_H
#include <string>
#include "Store.h"
using namespace std;

class Admin {
private:
    string username;
    string password;
public:
    void displayCatalog(const Store& store);
    void setUsername(const string& uname);
    void setPassword(const string& pwd);
    string getUsername() const;
    string getPassword() const;
    Admin();
    Admin(const string &uname);
    Admin(const string &uname, const string &pwd);
    ~Admin();
};

#endif

