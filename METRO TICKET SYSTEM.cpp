#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Station {
public:
    string name;
    Station(string n) : name(n) {}
};

class Metro {
public:
    int metro_id;
    vector<Station> route;
    Metro(int id, vector<Station> r) : metro_id(id), route(r) {}
};

class Ticket {
public:
    int ticket_id;
    Station source;
    Station destination;
    int fare;
    string timestamp;

    Ticket(int id, Station s, Station d, int f) : ticket_id(id), source(s), destination(d), fare(f) {
        time_t now = time(0);
        timestamp = ctime(&now);
    }

    void display_ticket() {
        cout << "Ticket ID: " << ticket_id << endl;
        cout << "Source: " << source.name << endl;
        cout << "Destination: " << destination.name << endl;
        cout << "Fare: " << fare << endl;
        cout << "Timestamp: " << timestamp;
    }
};

class BookingSystem {
private:
    vector<Ticket> tickets;
public:
    void book_ticket(Station source, Station destination, int fare) {
        int ticket_id = rand() % 100000000;
        Ticket ticket(ticket_id, source, destination, fare);
        tickets.push_back(ticket);
        cout << "\nTicket booked successfully!\n";
        ticket.display_ticket();
    }

    void display_all_tickets() {
        for (Ticket t : tickets) {
            t.display_ticket();
            cout << "----------------------\n";
        }
    }
};

int main() {
    // Seed random number generator
    srand(time(0));

    // Create stations
    Station station_a("Central");
    Station station_b("Airport");
    Station station_c("Downtown");

    // Create metro route
    vector<Station> route = {station_a, station_b, station_c};

    // Initialize booking system
    BookingSystem booking_system;

    // Book tickets
    booking_system.book_ticket(station_a, station_b, 50);
    booking_system.book_ticket(station_b, station_c, 40);

    // Display all tickets
    cout << "\nAll booked tickets:\n";
    booking_system.display_all_tickets();

    return 0;
}
