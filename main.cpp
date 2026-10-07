// Airline Ticket Reservation System using OOP in C++
// One flight, 10 seats. Reservations last until the program exits.
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Airline {
private:
    string passenger[10];
    bool booked[10];

public:
    Airline() {
        for (int i = 0; i < 10; i++) booked[i] = false;
    }

    void showSeats() {
        cout << "\n--- Seat Availability ---\n";
        for (int i = 0; i < 10; i++) {
            cout << "Seat " << i + 1 << ": "
                 << (booked[i] ? "Booked" : "Available") << "\n";
        }
    }

    void bookTicket() {
        int seat;
        showSeats();
        cout << "\nEnter seat number (1-10): ";
        if (!(cin >> seat)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (seat < 1 || seat > 10) {
            cout << "Invalid seat number!\n";
            return;
        }
        if (booked[seat - 1]) {
            cout << "This seat is already booked!\n";
            return;
        }
        string name;
        cout << "Enter passenger name: ";
        getline(cin, name);
        if (name.find_first_not_of(" \t") == string::npos) {
            cout << "Passenger name cannot be empty!\n";
            return;
        }
        passenger[seat - 1] = name;
        booked[seat - 1] = true;
        cout << "\nTicket booked successfully!\n";
        cout << "Passenger: " << name << "\n";
        cout << "Seat number: " << seat << "\n";
    }

    void displayReservations() {
        bool found = false;
        cout << "\n--- Reservations ---\n";
        for (int i = 0; i < 10; i++) {
            if (booked[i]) {
                cout << "Seat " << i + 1
                     << " | Passenger: " << passenger[i] << "\n";
                found = true;
            }
        }
        if (!found) cout << "No reservations found.\n";
    }

    void cancelTicket() {
        int seat;
        cout << "\nEnter seat number to cancel (1-10): ";
        if (!(cin >> seat)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            return;
        }
        if (seat < 1 || seat > 10) {
            cout << "Invalid seat number!\n";
            return;
        }
        if (!booked[seat - 1]) {
            cout << "This seat has no reservation.\n";
            return;
        }
        booked[seat - 1] = false;
        passenger[seat - 1] = "";
        cout << "Ticket cancelled successfully!\n";
    }
};

int main() {
    Airline flight;
    int choice = 0;
    do {
        cout << "\n===== AIRLINE RESERVATION SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Display Reservations\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Show Available Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1: flight.bookTicket(); break;
            case 2: flight.displayReservations(); break;
            case 3: flight.cancelTicket(); break;
            case 4: flight.showSeats(); break;
            case 5: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
