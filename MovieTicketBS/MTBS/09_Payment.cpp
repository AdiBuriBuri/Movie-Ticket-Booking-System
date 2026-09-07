#ifndef PAYMENT_CPP
#define PAYMENT_CPP

#include <iostream>
using namespace std;


class Payment{
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment(){}
};

class UpiPayment: public Payment{
public:
    
    bool pay(double amount){
        cout << "UPI Rs." << amount << " paid successfully" << endl;
        return true;
    }
};

class CardPayment: public Payment{
public:
    bool pay(double amount){
        cout << "Card Rs." << amount << " paid successfully" << endl;
        return true;
    }
};

class CashPayment: public Payment{
public:
    bool pay(double amount){
        cout << "Cash Rs." << amount << " paid successfully" << endl;
        return true;
    }
};

#endif
