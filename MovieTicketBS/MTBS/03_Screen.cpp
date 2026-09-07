#ifndef SCREEN_CPP
#define SCREEN_CPP

#include <string>
#include <vector>
#include "02_Seats.cpp"
using namespace std;

class Screen{
private:
    int screenNumber;
    vector<Seat>seats;
    
public:
    Screen(int screenNumber){
        this->screenNumber = screenNumber;
        seats.push_back(Seat("A1","PLATINUM"));  // Seat(seatnumber,seattype)
        seats.push_back(Seat("A2","PLATINUM"));
        seats.push_back(Seat("A3","PLATINUM"));
        seats.push_back(Seat("A4","PLATINUM"));
        seats.push_back(Seat("A5","PLATINUM"));
        seats.push_back(Seat("B1","GOLD"));  // Seat(seatnumber,seattype)
        seats.push_back(Seat("B2","GOLD"));
        seats.push_back(Seat("B3","GOLD"));
        seats.push_back(Seat("B4","GOLD"));
        seats.push_back(Seat("B5","GOLD"));
        seats.push_back(Seat("C1","SILVER"));  // Seat(seatnumber,seattype)
        seats.push_back(Seat("C2","SILVER"));
        seats.push_back(Seat("C3","SILVER"));
        seats.push_back(Seat("C4","SILVER"));
        seats.push_back(Seat("C5","SILVER"));
    }
    
    int getScreenNumber(){return screenNumber;}
    vector<Seat> &getSeats(){return seats;}
};


#endif
