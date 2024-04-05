#include "Admin.h"
#include "Store.h"

void Admin::displayCatalog(const Store& store) {
    cout << "Catalog of available products:\n";
    store.showCatalog();
}
void Admin::setUsername(const string& uname) {
    username = uname;
}
void Admin::setPassword(const string& pwd) {
    password = pwd;
}
string Admin::getUsername() const {
    return username;
}
string Admin::getPassword() const {
    return password;
}
Admin::Admin(const string& uname, const string& pwd) : username(uname), password(pwd) {
}
Admin::~Admin() {
}
