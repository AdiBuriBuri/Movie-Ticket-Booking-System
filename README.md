# 🎬 Movie Ticket Booking System — C++

A console-based **Movie Ticket Booking System** developed in C++ as part of the **TCS-504 System Design** assignment.

The project focuses on **Object-Oriented Programming (OOP)**, **UML-based system design**, and the application of **SOLID principles**.

---

## 📌 Features

- 🎥 Display movies currently playing
- 🕐 Display shows with screen number and start time
- 💺 Display seat layout with `AVAILABLE / BOOKED` status
- 🎟️ Book one or more seats
- 🚫 Reject invalid or already-booked seats
- 💰 Calculate ticket price based on seat type
- 💳 Pay using UPI, Card, or Cash
- 🎫 Generate and print booking ticket
- ❌ Cancel bookings
- 🔄 Release seats after cancellation or failed payment
- ✅ Validate invalid input

---

## 🏗️ Project Structure

```text
MTBS/
│
├── 01_Movie.cpp
├── 02_Seats.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PriceCalculator.cpp
├── 11_TicketPrinter.cpp
├── 12_BookingService.cpp
├── main.cpp
Data/
├── Class-Diagram.png
├── Sequence-Diagram.png
└── Report
```

The project follows a modular structure with separate source files for the major classes.

---

## 🧩 Classes

| Class | Responsibility |
|---|---|
| `Movie` | Stores movie information |
| `Seat` | Represents a physical seat |
| `Screen` | Contains seats for a screen |
| `Cinema` | Contains cinema screens |
| `Show` | Represents a movie screening |
| `ShowSeat` | Maintains seat status for a particular show |
| `Customer` | Stores customer information |
| `Booking` | Stores booking details and status |
| `Payment` | Abstract payment class |
| `UpiPayment` | Handles UPI payment |
| `CardPayment` | Handles card payment |
| `CashPayment` | Handles cash payment |
| `PriceCalculator` | Calculates booking price |
| `TicketPrinter` | Prints ticket details |
| `BookingService` | Handles the booking workflow |

---

## 🔄 Booking Flow

```text
Customer
   │
   ▼
Select Movie
   │
   ▼
Select Show
   │
   ▼
Select Seat
   │
   ▼
Check Seat Availability
   │
   ▼
Book Seat
   │
   ▼
Calculate Price
   │
   ▼
Select Payment Method
   │
   ▼
Process Payment
   │
   ├── Payment Failed
   │       │
   │       ▼
   │   Release Seats
   │       │
   │       ▼
   │   Booking Failed
   │
   └── Payment Successful
           │
           ▼
      Create Booking
           │
           ▼
      Print Ticket
```

---

## 💰 Seat Pricing

The assignment requires:

| Seat Type | Price |
|---|---:|
| SILVER | ₹150 |
| GOLD | ₹250 |
| PLATINUM | ₹400 |

---

## 📐 UML Design

### Class Diagram

The class diagram represents:

- Classes, attributes and methods
- Composition
- Aggregation
- Association
- Inheritance
- Multiplicities
- The abstract `Payment` class

### Sequence Diagram

The sequence diagram represents the use case:

> **Customer books 1 seat and pays by UPI**

Main interaction:

```text
main()
   │
   ├── creates UpiPayment
   │
   ▼
BookingService
   │
   ▼
Show
   │
   ▼
ShowSeat
   │
   ▼
PriceCalculator
   │
   ▼
Payment (UpiPayment)
   │
   ▼
Booking
   │
   ▼
TicketPrinter
```

---

## 🧠 OOP Concepts Used

### Encapsulation

Data members are kept `private` and accessed through public methods.

Example:

```cpp
bool bookSeat();
void cancelSeat();
```

### Abstraction

`Payment` is an abstract class:

```cpp
class Payment {
public:
    virtual bool pay(double amount) = 0;
};
```

### Inheritance

Concrete payment classes inherit from `Payment`:

```cpp
class UpiPayment : public Payment
class CardPayment : public Payment
class CashPayment : public Payment
```

### Runtime Polymorphism

A base-class pointer can refer to different payment implementations:

```cpp
Payment *payment;

payment = new UpiPayment();
payment->pay(amount);
```

### Static Members

`Booking::nextID` is used to generate unique booking IDs.

### Composition

```text
Cinema ◆── Screen
Screen ◆── Seat
Show ◆── ShowSeat
```

### Association

Examples include:

```text
Show ──▶ Movie
Show ──▶ Screen
Booking ──▶ Customer
Booking ──▶ Show
```

---

## 🧱 SOLID Principles

### S — Single Responsibility Principle

Each class focuses on one main responsibility.

```text
PriceCalculator → Pricing
TicketPrinter   → Printing
ShowSeat        → Seat status
Payment         → Payment contract
BookingService  → Booking workflow
```

### O — Open/Closed Principle

The payment system can be extended with another payment type such as:

```cpp
class NetBankingPayment : public Payment
{
    // New payment implementation
};
```

without changing the existing payment-processing logic.

### L — Liskov Substitution Principle

`UpiPayment`, `CardPayment`, and `CashPayment` can be used through the `Payment` base class.

### I — Interface Segregation Principle

The `Payment` abstraction contains only payment-related behavior and does not force unrelated operations on every payment method.

### D — Dependency Inversion Principle

`BookingService` receives a `Payment*` instead of directly creating a specific payment implementation.

---

## 🛡️ Edge Cases

The system is designed to handle:

```text
Already-booked seat
        ↓
Booking rejected

Invalid seat
        ↓
Clear error message

Payment failure
        ↓
Seats released
        ↓
Booking not confirmed

Booking cancellation
        ↓
Seats become AVAILABLE
```

---

## ▶️ How to Compile and Run

Compile using C++17:

```bash
g++ -std=c++17 main.cpp -o movie_booking
```

Run:

```bash
./movie_booking
```

---

## 🎟️ Example Ticket

```text
================ TICKET ================

Booking ID : BK1001
Movie      : Gladiator
Screen     : Screen: 1
Seats      : A1
Amount     : Rs.400
Status     : CONFIRMED

=========================================
```

---

## 📚 System Design

This project includes:

- UML Class Diagram
- UML Sequence Diagram
- Requirement Analysis
- Noun–Verb Analysis
- Relationship Analysis
- SOLID Principle Mapping
- Modular C++ Implementation

---

## 🎯 Objective

The main objective of this project is to understand how **system design and implementation work together**.

Rather than only writing code, the project focuses on:

- Designing class responsibilities
- Understanding object relationships
- Applying OOP concepts
- Modeling interactions using UML
- Applying SOLID principles
- Building a modular and maintainable system

---

## 👨‍💻 Author

**Aditya Bisht**

B.Tech. CSE  
System Design — TCS-504

---

## ⭐ Keywords

`C++` `OOP` `System Design` `UML` `SOLID` `Movie Ticket Booking` `Object Oriented Programming` `Software Engineering`
