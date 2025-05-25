#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtStart(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode; // inserting at end
        }
        temp->next = newNode;
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        if (head == tail) { // Only one node
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        if (head == tail) { // Only one node
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void deleteFromPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            deleteFromStart();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            if (temp == NULL) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Element " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << val << " not found in the list\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List (Forward): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value, position;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> value;
                list.insertAtStart(value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                list.deleteFromStart();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
