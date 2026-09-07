#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include <string>
using namespace std;

class Customer{
private:
    string name;
    string phone;
    int age;
    string cid; // customer id
public:
    Customer(string name,string phone,int age,string cid){
        this->name = name;
        this->phone = phone;
        this->age = age;
        this->cid = cid;
    }
    
    string getName(){return name;}
    string getPhone(){return phone;}
    string getCustomerID(){return cid;}
    int getAge(){return age;}
};

#endif
