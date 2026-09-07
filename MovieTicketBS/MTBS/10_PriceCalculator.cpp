#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP

#include <iostream>
#include <vector>
#include "05_Show.cpp"
using namespace std;

class PriceCalculator{
private:
    static const int SILVER_PRICE = 99;
    static const int GOLD_PRICE = 299;
    static const int PLATINUM_PRICE = 499;
    
public:
    static double calculate(Show &show, vector<string> &seatNumbers){
        double total = 0.0;
        
        for(const string& seatNo: seatNumbers){
            ShowSeat *seat = show.getSeat(seatNo);
            
            if(seat != nullptr){
                string stype = seat->getSeatType();
                if(stype == "SILVER") total += SILVER_PRICE;
                else if(stype == "GOLD") total += GOLD_PRICE;
                else if (stype == "PLATINUM") total += PLATINUM_PRICE;
            }
        }
        return total;
    }
};

#endif
