#ifndef BOOKINDSERVICES_CPP
#define BOOKINDSERVICES_CPP

#include <iostream>
#include <vector>
#include <string>
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PriceCalculator.cpp"
#include "11_TicketPrinter.cpp"
using namespace std;

class BookingService
{
public:
    Booking processBooking(Customer &customer, Show &show, vector<string> &seatNumbers, Payment *paymentMethod)
    {
        for (const string &seatNo : seatNumbers)
        {
            ShowSeat *seat = show.getSeat(seatNo);
            if (seat == nullptr || seat->isBooked())
            {
                cout << "Error " << seatNo << " is already booked or invalid" << endl;
                return Booking(customer, show, seatNumbers, 0, "FAILED");
            }
        }

        for (const string &seatNo : seatNumbers)
        {
            show.getSeat(seatNo)->bookSeat();
        }

        double totalAmount = PriceCalculator::calculate(show, seatNumbers);

        if (!paymentMethod->pay(totalAmount))
        {
            cout << "Payment Failed. Releasing seats..." << endl;
            for (auto seatNo : seatNumbers)
            {
                show.getSeat(seatNo)->cancelSeat();
            }
            return Booking(customer, show, seatNumbers, totalAmount, "FAILED");
        }
        Booking booking(customer, show, seatNumbers, totalAmount, "CONFIRMED");
        TicketPrinter::printTicket(booking);
        return booking;
    }
};

#endif
