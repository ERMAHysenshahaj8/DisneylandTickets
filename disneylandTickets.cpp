// Include necessary libraries
#include <iostream>
#include <string>

using namespace std;

// Structure to represent a Disneyland booking ticket
struct Ticket {
    string ticketType;
    double price;
    Ticket* next; // Pointer to the next ticket in the linked list

    Ticket(string type, double cost) : ticketType(type), price(cost), next(nullptr) {}
};

// Class to manage the collection of Disneyland booking tickets
class TicketCollection {
private:
    Ticket* head; // Pointer to the head of the linked list

public:
    TicketCollection() : head(nullptr) {}

    // Function to add a ticket to the collection
    void addTicket(string type, double price) {
        Ticket* newTicket = new Ticket(type, price);
        newTicket->next = head;
        head = newTicket;
        cout << "Ticket added successfully!" << endl;
    }

    // Function to display all tickets in the collection
    void displayAllTickets() {
        Ticket* current = head;
        cout << "All Tickets in the Collection:" << endl;
        while (current != nullptr) {
            cout << "Type: " << current->ticketType << ", Price: $" << current->price << endl;
            current = current->next;
        }
        cout << endl;
    }

    // Function to search for tickets that meet a certain condition
    void searchTickets(double maxPrice) {
        Ticket* current = head;
        cout << "Tickets with Price less than or equal to $" << maxPrice << ":" << endl;
        while (current != nullptr) {
            if (current->price <= maxPrice) {
                cout << "Type: " << current->ticketType << ", Price: $" << current->price << endl;
            }
            current = current->next;
        }
        cout << endl;
    }

    // Function to display the item according to a given criteria (e.g., ticket type)
    void displayTicketByType(string type) {
        Ticket* current = head;
        cout << "Tickets of Type " << type << ":" << endl;
        while (current != nullptr) {
            if (current->ticketType == type) {
                cout << "Type: " << current->ticketType << ", Price: $" << current->price << endl;
            }
            current = current->next;
        }
        cout << endl;
    }

    // Function to find the minimum price of a ticket
    double findMinPrice() {
        if (head == nullptr) {
            cout << "Collection is empty!" << endl;
            return -1; // Return -1 as an indication of an error
        }

        Ticket* current = head;
        double minPrice = current->price;

        while (current != nullptr) {
            if (current->price < minPrice) {
                minPrice = current->price;
            }
            current = current->next;
        }

        return minPrice;
    }

    // Function to find the maximum price of a ticket
    double findMaxPrice() {
        if (head == nullptr) {
            cout << "Collection is empty!" << endl;
            return -1; // Return -1 as an indication of an error
        }

        Ticket* current = head;
        double maxPrice = current->price;

        while (current != nullptr) {
            if (current->price > maxPrice) {
                maxPrice = current->price;
            }
            current = current->next;
        }

        return maxPrice;
    }

    // Function to calculate the average price of tickets
    double calculateAveragePrice() {
        if (head == nullptr) {
            cout << "Collection is empty!" << endl;
            return -1; // Return -1 as an indication of an error
        }

        Ticket* current = head;
        double sum = 0.0;
        int count = 0;

        while (current != nullptr) {
            sum += current->price;
            count++;
            current = current->next;
        }

        return sum / count;
    }
};

int main() {
    TicketCollection disneylandTickets;

    // Adding tickets to the collection
    disneylandTickets.addTicket("Adult", 75.0);
    disneylandTickets.addTicket("Child", 50.0);
    disneylandTickets.addTicket("VIP", 150.0);

    // Displaying all tickets
    disneylandTickets.displayAllTickets();

    // Searching for tickets with price less than or equal to $100
    disneylandTickets.searchTickets(100.0);

    // Displaying tickets of a specific type
    disneylandTickets.displayTicketByType("Child");

    // Finding the minimum price of a ticket
    double minPrice = disneylandTickets.findMinPrice();
    if (minPrice != -1) {
        cout << "Minimum Price: $" << minPrice << endl;
    }

    // Finding the maximum price of a ticket
    double maxPrice = disneylandTickets.findMaxPrice();
    if (maxPrice != -1) {
        cout << "Maximum Price: $" << maxPrice << endl;
    }

    // Calculating the average price of tickets
    double avgPrice = disneylandTickets.calculateAveragePrice();
    if (avgPrice != -1) {
        cout << "Average Price: $" << avgPrice << endl;
    }

    return 0;
}
