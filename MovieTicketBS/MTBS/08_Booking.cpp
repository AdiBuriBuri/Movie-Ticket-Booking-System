#ifndef BOOKING_CPP
#define BOOKING_CPP

#include <string>
#include <vector>
#include "07_Customer.cpp"
#include "05_Show.cpp"
using namespace std;

class Booking
{
private:
    static int nextID;
    string bookingID;
    Customer customer;
    Show &show;
    vector<string> seatNumbers;
    double totalAmount;
    string status;

public:
    Booking(Customer customer, Show &show, vector<string> seatNumbers, double totalAmount, string status) : customer(customer), show(show)
    {
        this->bookingID = "BK" + to_string(nextID++);
        this->seatNumbers = seatNumbers;
        this->totalAmount = totalAmount;
        this->status = status;
    }

    string getBookingID() { return bookingID; }

    string getMovieName() { return show.getMovie()->getTitle(); }

    vector<string> getBookedSeatNumbers() { return seatNumbers; }

    double getTotalAmount() { return totalAmount; }

    string getStatus() { return status; }

    void setStatus(string status)
    {
        this->status = status;
    }

    string getStartTime()
    {
        return show.getStartTime();
    }
    string getScreenName() { return "Screen: " + to_string(show.getScreen()->getScreenNumber()); }
};

int Booking::nextID = 1001;
#endif
