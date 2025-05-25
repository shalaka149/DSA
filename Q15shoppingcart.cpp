#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int quantity;
    float price;
    Item* next;
};

class ShoppingCart {
private:
    Item* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    void addItem(string name, int quantity, float price) {
        Item* newItem = new Item{name, quantity, price, nullptr};

        if (!head) {
            head = newItem;
        } else {
            Item* temp = head;
            while (temp->next != nullptr){
            temp = temp->next;
            }
            temp->next = newItem;
        }

        cout << "Item added to cart.\n";
    }

    void removeItem(string name) {
        Item* temp = head;
        Item* prev = nullptr;

        while (temp && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Item not found.\n";
            return;
        }

        if (!prev) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Item removed from cart.\n";
    }

    void updateQuantity(string name, int newQuantity) {
        Item* temp = head;

        while (temp && temp->name != name) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Item not found.\n";
            return;
        }

        temp->quantity = newQuantity;
        cout << "Quantity updated.\n";
    }

    void displayCart() {
        Item* temp = head;
        float total = 0;

        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "\nItems in Cart:\n";
        cout << "-----------------------------\n";
        while (temp) {
            cout << "Name: " << temp->name 
                 << ", Quantity: " << temp->quantity 
                 << ", Price: " << temp->price 
                 << ", Total: " << temp->quantity * temp->price << endl;
            total += temp->quantity * temp->price;
            temp = temp->next;
        }
        cout << "-----------------------------\n";
        cout << "Total Cart Value: " << total << "\n";
    }

    ~ShoppingCart() {
        while (head) {
            Item* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string name;
    int quantity;
    float price;

    do {
        cout << "\n===== Shopping Cart Menu =====\n";
        cout << "1. Add Item\n2. Remove Item\n3. Update Quantity\n4. Display Cart\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cart.addItem(name, quantity, price);
            break;
        case 2:
            cout << "Enter item name to remove: ";
            cin >> name;
            cart.removeItem(name);
            break;
        case 3:
            cout << "Enter item name to update: ";
            cin >> name;
            cout << "Enter new quantity: ";
            cin >> quantity;
            cart.updateQuantity(name, quantity);
            break;
        case 4:
            cart.displayCart();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
