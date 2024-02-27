#include "Purchase.h"
#include <iostream>
using namespace std;

void Purchase::SetPrice(float new_productPrice) {
    productPrice=new_productPrice;
}
void Purchase::SetAmount(int new_amount) {
    amount=new_amount;
}
int Purchase::getAmount() {
    return amount;
}
float Purchase::getProductPrice() {
    return productPrice;
}
Purchase::~Purchase() {
}
Purchase::Purchase(float new_productPrice,int new_amount):productPrice{new_productPrice},amount{new_amount}{

}