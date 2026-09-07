#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP

#include <iostream>
#include "08_Booking.cpp"
using namespace std;

class TicketPrinter
{
public:
    static void printTicket(Booking &booking)
    {
        cout << "Booking ID: " << booking.getBookingID() << endl;
        cout << "Movie     : " << booking.getMovieName() << endl;
        cout << "Screen    : " << booking.getScreenName() << endl;
        cout << "Seats     : ";

        vector<string> seats = booking.getBookedSeatNumbers();
        for (int i = 0; i < seats.size(); i++)
        {
            cout << seats[i];
        }
        cout << endl;
        cout << "Amount    : Rs." << booking.getTotalAmount() << endl;
        cout << "status    : " << booking.getStatus() << endl;
    }
};

#endif
