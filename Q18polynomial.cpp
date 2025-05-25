#include <iostream>
using namespace std;

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    Node* next;
    
    Node(int c, int e) {
        coefficient = c;
        exponent = e;
        next = nullptr;
    }
};

// Class to represent a Polynomial
class Polynomial {
private:
    Node* head;

public:
    // Constructor
    Polynomial() : head(nullptr) {}

    // Copy Constructor (deep copy, needed because we pass by value)
    Polynomial(const Polynomial& other) {
        head = nullptr;
        Node* temp = other.head;
        while (temp != nullptr) {
            insertTerm(temp->coefficient, temp->exponent);
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~Polynomial() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert a new term
    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);

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

    // Function to input a polynomial
    void inputPolynomial() {
        int n;
        cout << "Enter the number of terms: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int coeff, exp;
            cout << "Enter coefficient and exponent for term " << i + 1 << " (format: coefficient exponent): ";
            cin >> coeff >> exp;
            insertTerm(coeff, exp);
        }
    }

    // Function to display the polynomial
    void displayPolynomial() const {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "0";
        }
        while (temp != nullptr) {
            if (temp->coefficient > 0 && temp != head) {
                cout << " + ";
            }
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to add two polynomials
    Polynomial addPolynomials(Polynomial other) {  // pass by value
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            } else if (p2 == nullptr) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else {
                if (p1->exponent == p2->exponent) {
                    result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                    p1 = p1->next;
                    p2 = p2->next;
                } else if (p1->exponent > p2->exponent) {
                    result.insertTerm(p1->coefficient, p1->exponent);
                    p1 = p1->next;
                } else {
                    result.insertTerm(p2->coefficient, p2->exponent);
                    p2 = p2->next;
                }
            }
        }

        return result;
    }
};

int main() {
    Polynomial poly1, poly2, result;

    // Input first polynomial
    cout << "Input for the first polynomial:" << endl;
    poly1.inputPolynomial();

    // Input second polynomial
    cout << "Input for the second polynomial:" << endl;
    poly2.inputPolynomial();

    // Display polynomials
    cout << "\nFirst Polynomial: ";
    poly1.displayPolynomial();

    cout << "Second Polynomial: ";
    poly2.displayPolynomial();

    // Add polynomials
    result = poly1.addPolynomials(poly2);

    // Display result
    cout << "Result of Addition: ";
    result.displayPolynomial();

    return 0;
}
