#include <iostream>
#include <string>

using namespace std;

struct Appointment {
    string time;
    string description;
};

struct Node {
    string date;  // Date in YYYY-MM-DD format
    Appointment appointment;
    Node* left;
    Node* right;

    // Constructor with value parameters
    Node(string d, string t, string desc) {
        date = d;
        left = nullptr;
        right = nullptr;
        appointment.time = t;
        appointment.description = desc;
    }
};

class BSTCalendar {
private:
    Node* root;

    // Insert function with value parameters
    Node* insert(Node* node, string date, string time, string description) {
        if (node == nullptr) 
            return new Node(date, time, description);  // Create a new node if the node is null

        if (date < node->date) 
            node->left = insert(node->left, date, time, description);  // Insert in left subtree
        else if (date > node->date) 
            node->right = insert(node->right, date, time, description);  // Insert in right subtree
        
        return node;
    }

    // Search function with value parameter
    Node* search(Node* node, string date) {
        if (node == nullptr || node->date == date)
            return node;

        if (date < node->date)
            return search(node->left, date);

        return search(node->right, date);
    }

    // In-order traversal with date order
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);  // Traverse left subtree
            cout << "Date: " << node->date << "\n"
                 << "Time: " << node->appointment.time << "\n"
                 << "Description: " << node->appointment.description << "\n"
                 << "----------------------------\n";
            inOrder(node->right);  // Traverse right subtree
        }
    }

public:
    // Constructor for the BSTCalendar class
    BSTCalendar() {
        root = nullptr;  // Explicitly initialize root to nullptr
    }
    
    // Public insert function to add an appointment
    void insertAppointment(string date, string time, string description) {
        root = insert(root, date, time, description);
    }

    // Public function to search for an appointment by date
    void searchAppointment(string date) {
        Node* result = search(root, date);
        if (result != nullptr) {
            cout << "Appointment found on " << result->date << ":\n"
                 << "Time: " << result->appointment.time << "\n"
                 << "Description: " << result->appointment.description << "\n";
        } else {
            cout << "No appointment found on " << date << ".\n";
        }
    }

    // Public function to list all appointments in date order
    void listAppointments() {
        if (root == nullptr) {
            cout << "No appointments scheduled yet.\n";
        } else {
            inOrder(root);
        }
    }
};

int main() {
    BSTCalendar calendar;
    int choice;
    string date, time, description;

    do {
        cout << "\n--- Calendar Scheduler ---\n";
        cout << "1. Add an Appointment\n";
        cout << "2. Search for Appointment by Date\n";
        cout << "3. List All Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter time: ";
                cin >> time;
                cout << "Enter description: ";
                cin.ignore();  // to clear the buffer before reading the full line
                getline(cin, description);  // to allow multi-word descriptions
                calendar.insertAppointment(date, time, description);
                break;
            case 2:
                cout << "Enter date (YYYY-MM-DD) to search for: ";
                cin >> date;
                calendar.searchAppointment(date);
                break;
            case 3:
                cout << "Listing all appointments:\n";
                calendar.listAppointments();
                break;
            case 4:
                cout << "Exiting the Calendar Scheduler. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
