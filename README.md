Airline Ticket Reservation System ✈️

A beginner-friendly, menu-driven C++ console application for managing airline seat reservations. Built using Object-Oriented Programming (OOP), this project demonstrates how a class can keep booking data and related operations together.
Features
Book a ticket by selecting a seat and entering a passenger name.
View reservations with passenger names and seat numbers.
Cancel a ticket and make the seat available again.
Check availability for all 10 seats.
Prevent duplicate bookings and invalid seat selections.
Handle non-numeric menu and seat inputs and reject blank passenger names.
Support passenger names containing spaces.
Technology
Language: C++
Interface: Terminal / console
Libraries: iostream, string, limits
Dependencies: A C++ compiler; no third-party libraries required

How It Works
The Airline class stores passenger names in passenger[10] and seat status in booked[10]. Seat numbers shown to users range from 1 to 10, while array indexes range from 0 to 9.
Booking a seat stores the passenger's name and sets its status to true. Cancelling clears the name and sets the status back to false.

Verification
The program was compiled with g++ using C++11 and the -Wall -Wextra -pedantic flags. A sample booking, reservation display, cancellation, empty-reservation display, and exit sequence was checked successfully.
Current Limitations
Manages one flight with 10 seats.
Reservations are stored in memory and are lost when the program exits.
Does not include flight schedules, fares, payments, or user accounts.
This is an educational simulation and does not connect to real airline booking services.
Possible Future Improvements
Save and load reservations using file handling.
Support multiple flights, routes, and travel dates.
Generate unique booking IDs.
Add fare calculation and ticket categories.
Export a printable ticket or booking receipt.
Author
Swaraj
Created as a C++ OOP learning project.
