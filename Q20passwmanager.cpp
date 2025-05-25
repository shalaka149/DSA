#include <iostream>
#include <string>
using namespace std;

// Node class to store credentials
class Node {
public:
    string website;
    string username;
    string password;
    Node* next;

    // Constructor with parameters having different names to avoid ambiguity
    Node(string website1, string username1, string password1) {
        website = website1;
        username = username1;
        password = password1;
        next = nullptr;
    }
};

// PasswordManager class to manage the linked list of credentials
class PasswordManager {
private:
    Node* head;

public:
    // Constructor
    PasswordManager() {
        head = nullptr;
    }

    // Function to add new credentials to the list
    void addCredentials(string website, string username, string password) {
        Node* newNode = new Node(website, username, password);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to encrypt password (shift characters)
    string encryptPassword(string password, int shift = 3) {
        for (int i = 0; i < password.length(); i++) {
            password[i] = password[i] + shift;  // Shift characters by 3
        }
        return password;
    }

    // Function to decrypt password (reverse the character shift)
    string decryptPassword(string password, int shift = 3) {
        for (int i = 0; i < password.length(); i++) {
            password[i] = password[i] - shift;  // Reverse the shift
        }
        return password;
    }

    // Function to remove credentials by website
    void removeCredentials(string website) {
        if (head == nullptr) {
            cout << "No credentials to remove!" << endl;
            return;
        }
        if (head->website == website) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Credentials for " << website << " removed." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->website != website) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Website not found!" << endl;
        } else {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Credentials for " << website << " removed." << endl;
        }
    }

    // Function to update password for a website
    void updatePassword(string website, string newPassword) {
        Node* current = head;
        while (current != nullptr && current->website != website) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Website not found!" << endl;
        } else {
            current->password = encryptPassword(newPassword);  // Encrypt new password
            cout << "Password updated for " << website << endl;
        }
    }

    // Function to search for credentials by website name
    void searchCredentials(string website) {
        Node* current = head;
        while (current != nullptr && current->website != website) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Website not found!" << endl;
        } else {
            cout << "Website: " << current->website << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << decryptPassword(current->password) << endl;  // Decrypt password
        }
    }

    // Function to display all stored credentials
    void displayCredentials() {
        if (head == nullptr) {
            cout << "No credentials stored!" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << "Website: " << current->website << endl;
            cout << "Username: " << current->username << endl;
            cout << "Password: " << decryptPassword(current->password) << endl;  // Decrypt password
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }

    // Destructor to free memory when the PasswordManager is destroyed
    ~PasswordManager() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PasswordManager manager;
    int choice;
    string website, username, password;

    while (true) {
        cout << "\nPassword Manager Menu:" << endl;
        cout << "1. Add Credentials" << endl;
        cout << "2. Remove Credentials" << endl;
        cout << "3. Update Password" << endl;
        cout << "4. Search Credentials" << endl;
        cout << "5. Display All Credentials" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter website name: ";
                cin >> website;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                password = manager.encryptPassword(password);  // Encrypt password before storing
                manager.addCredentials(website, username, password);
                break;
            case 2:
                cout << "Enter website to remove: ";
                cin >> website;
                manager.removeCredentials(website);
                break;
            case 3:
                cout << "Enter website to update password: ";
                cin >> website;
                cout << "Enter new password: ";
                cin >> password;
                manager.updatePassword(website, password);
                break;
            case 4:
                cout << "Enter website to search: ";
                cin >> website;
                manager.searchCredentials(website);
                break;
            case 5:
                manager.displayCredentials();
                break;
            case 6:
                cout << "Exiting Password Manager." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}
