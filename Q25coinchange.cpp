#include <iostream>
using namespace std;

// Coin class to represent individual coin denominations
class Coin {
public:
    int value;   // Coin value (e.g., 1, 2, 5, 10, etc.)
    Coin* next;  // Pointer to the next coin in the list

    // Constructor to initialize a coin with a value
    Coin(int value1) {
        value = value1;
        next = nullptr;
    }
};

// CoinChange class to manage the list of coins and operations
class CoinChange {
private:
    Coin* head;  // Head of the linked list of coins

public:
    // Constructor to initialize the head to nullptr
    CoinChange() {
        head = nullptr;
    }

    // Function to insert a coin into the list (sorted in descending order)
    void insertCoin(int value) {
        Coin* newCoin = new Coin(value);
        if (head == nullptr || head->value <= value) {
            newCoin->next = head;
            head = newCoin;
        } else {
            Coin* temp = head;
            while (temp->next != nullptr && temp->next->value > value) {
                temp = temp->next;
            }
            newCoin->next = temp->next;
            temp->next = newCoin;
        }
    }

    // Function to display the coin types available
    void displayCoins() {
        if (head == nullptr) {
            cout << "No coins available." << endl;
            return;
        }
        cout << "Available coin denominations: ";
        Coin* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to calculate the minimum number of coins for a given amount
    void calculateChange(int amount) {
        int totalCoins = 0;
        cout << "Breakdown for " << amount << " units: " << endl;

        Coin* current = head;
        while (current != nullptr && amount > 0) {
            int coinCount = amount / current->value; // Number of coins of this denomination
            totalCoins += coinCount;
            if (coinCount > 0) {
                cout << coinCount << " coins of " << current->value << " value" << endl;
                amount %= current->value;  // Update amount after using these coins
            }
            current = current->next; // Move to the next coin type
        }

        if (amount > 0) {
            cout << "Remaining amount that cannot be broken down: " << amount << endl;
        } else {
            cout << "Total coins used: " << totalCoins << endl;
        }
    }

    // Destructor to free memory when the CoinChange object is destroyed
    ~CoinChange() {
        while (head) {
            Coin* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CoinChange coinSystem;  // Create a CoinChange object

    // Insert available coin denominations (sorted in descending order)
    coinSystem.insertCoin(10);
    coinSystem.insertCoin(5);
    coinSystem.insertCoin(2);
    coinSystem.insertCoin(1);

    coinSystem.displayCoins();  // Display the available coin denominations

    int amount;
    cout << "Enter the amount to break down into coins: ";
    cin >> amount;

    coinSystem.calculateChange(amount);  // Calculate the minimum coins for the given amount

    return 0;
}
