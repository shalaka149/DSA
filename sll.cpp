#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
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
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
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
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of range\n";
                return;
            }
            temp = temp->next;
        }

        Node* delNode = temp->next;
        if (delNode == NULL) {
            cout << "Position out of range\n";
            return;
        }

        temp->next = delNode->next;
        if (temp->next == NULL) {
            tail = temp;
        }
        delete delNode;
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
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, position;

    do {
        cout << "\n--- Linked List Menu ---\n";
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
