//
//  01_Movie.cpp
//
//
//  Created by Aditya Bisht on 06/09/26.
//
#ifndef SEATS_CPP
#define SEATS_CPP

#include <string>
using namespace std;

class Seat{
private:
    string seatNumber;
    string seatType;
    
public:
    Seat(string seatNumber,string seatType){
        this->seatNumber = seatNumber;
        this->seatType = seatType;
    }
    
    string getSeatNumber(){
        return seatNumber;
    }
    string getSeatType(){
        return seatType;
    }
};

#endif
