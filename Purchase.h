#ifndef INC_2_PURCHASE_H
#define INC_2_PURCHASE_H
#include <iostream>
#include <string>
using namespace std;

class Purchase{
private:
    float productPrice;
    int amount;
public:
    void SetPrice(float new_productPrice);
    void SetAmount(int new_amount);
    float getProductPrice();
    int getAmount();
    Purchase();
    Purchase(float new_productPrice);
    Purchase(float new_productPrice, int new_amount);
    ~Purchase();
};
#endif