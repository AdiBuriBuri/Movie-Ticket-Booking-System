#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP

#include <string>
using namespace std;

class ShowSeat{
private:
    string seatNumber;
    string seatType;
    bool is_booked;
    
public:
    ShowSeat(string seatNumber,string seatType){
        this->seatNumber = seatNumber;
        this->seatType = seatType;
        is_booked = false;
    }
  
    string getSeatNumber(){return seatNumber;}
    string getSeatType(){return seatType;}
    bool isBooked(){return is_booked;}
    
    bool bookSeat(){
        if(is_booked)return false;
        is_booked = true;
        return true;
    }
    
    void cancelSeat(){is_booked = false;}
};



#endif
