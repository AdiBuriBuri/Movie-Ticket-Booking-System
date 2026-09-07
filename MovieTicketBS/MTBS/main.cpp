#include <iostream>
#include <string>
#include <vector>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "12_BookingService.cpp"
using namespace std;

vector<string> parseSeats(string input)
{
    vector<string> seats;
    string currentSeat = "";

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',' || input[i] == ' ')
        {
            if (currentSeat != "")
            {
                seats.push_back(currentSeat);
                currentSeat = "";
            }
        }
        else
        {
            currentSeat += input[i];
        }
    }
    if (currentSeat != "")
    {
        seats.push_back(currentSeat);
    }
    return seats;
}

int main()
{
    Cinema imax("IMAX Cinemas");
    Movie m1("Gladiator", "Hindi", 220);
    Movie m2("Spider man Brand new day", "English", 190);

    Show show1(&m1, &imax.getScreens()[0], "06:00 PM");
    Show show2(&m2, &imax.getScreens()[1], "10:00 PM");

    Customer customer("Dhruv", "9483828124", 18, "ID2385A84");
    BookingService bookingService;
    vector<Booking> activeBookings;

    int choice;
    while (true)
    {
        cout << "---------- MOVIE TICKET BOOKING ----------" << endl;
        cout << "1. Movies 2. Book 3. Cancel 4. My Ticket 0.Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting application...." << endl;
            break;
        }
        else if (choice == 1)
        {
            cout << "[1] " << m1.getTitle() << " " << m1.getLanguage() << " " << m1.getDuration() << " min" << endl;
            cout << "[2] " << m2.getTitle() << " " << m2.getLanguage() << " " << m2.getDuration() << " min" << endl;
        }
        else if (choice == 2)
        {
            int uChoice, sChoice;
            cout << "Choose Movie: ";
            cin >> uChoice;
            Show *selectShow = (uChoice == 1) ? &show1 : &show2;

            cout << "\n[1] Screen-1 06:00 PM" << endl
                 << "\n[2] Screen-2 10:00 PM" << endl;

            cout << "Choose Show: ";
            cin >> sChoice;

            cout << "\nSCREEN-" << selectShow->getScreen()->getScreenNumber() << " " << selectShow->getStartTime() << endl;
            cout << selectShow->getMovie()->getTitle() << endl;

            cout << "SILVER ";
            for (auto s : selectShow->getShowSeats())
            {
                if (s.getSeatType() == "SILVER")
                {
                    cout << s.getSeatNumber() << (s.isBooked() ? "[X] " : "[] ");
                }
            }
            cout << "\nGOLD ";
            for (auto s : selectShow->getShowSeats())
            {
                if (s.getSeatType() == "GOLD")
                {
                    cout << s.getSeatNumber() << (s.isBooked() ? "[X] " : "[] ");
                }
            }

            cout << "\nPLATINUM ";
            for (auto s : selectShow->getShowSeats())
            {
                if (s.getSeatType() == "PLATINUM")
                {
                    cout << s.getSeatNumber() << (s.isBooked() ? "[X] " : "[] ");
                }
            }
            cout << "\n([] = available [X] = Booked" << endl;

            cout << "Seats (ex. A2,B2): ";
            string seatInput;
            cin >> seatInput;
            vector<string> chosenSeats = parseSeats(seatInput);

            int payChoice;
            cout << "Pay by: 1.UPI 2.Card 3.Cash - ";
            cin >> payChoice;

            Payment *payment = nullptr;
            if (payChoice == 1)
                payment = new UpiPayment();
            else if (payChoice == 2)
                payment = new CardPayment();
            else if (payChoice == 3)
                payment = new CashPayment();

            Booking b = bookingService.processBooking(customer, *selectShow, chosenSeats, payment);
            if (b.getStatus() == "CONFIRMED")
            {
                activeBookings.push_back(b);
            }
            delete payment;
        }
        else if (choice == 3)
        {
            cout << "Enter Booking ID to cancel: ";
            string bID;
            cin >> bID;
            bool found = false;
            for (int i = 0; i < activeBookings.size(); i++)
            {
                if (activeBookings[i].getBookingID() == bID)
                {
                    found = true;
                    activeBookings[i].setStatus("CANCELLED");
                    cout << "\nBooking " << bID << " cancelled." << endl
                         << endl;
                    break;
                }
            }
            if (!found)
                cout << "Booking ID not found" << endl;
        }
        else if (choice == 4)
        {
            cout << "\n ---- MY BOOKING ----" << endl;
            if (activeBookings.empty())
            {
                cout << "\nNo Bookings yet\n"
                     << endl;
            }
            for (int i = 0; i < activeBookings.size(); i++)
            {
                cout << "\nID: " << activeBookings[i].getBookingID() << " | Movie: " << activeBookings[i].getMovieName() << " | Status: " << activeBookings[i].getStatus() << endl
                     << endl;
            }
        }
    }
    return 0;
}
