
//First come first served

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
};

int main() {
    queue<Patient> patientQueue;
    int choice;
    Patient p;

    do {
        cout << "\n=== Hospital Patient Queue System ===\n";
        cout << "1. Register Patient\n";
        cout << "2. Serve Next Patient\n";
        cout << "3. Show Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> p.name;
                cout << "Enter severity (1-10): ";
                cin >> p.severity;
                patientQueue.push(p);
                cout << "Patient " << p.name << " registered.\n";
                break;

            case 2:
                if (!patientQueue.empty()) {
                    Patient next = patientQueue.front();
                    cout << "Serving patient: " << next.name << " (Severity: " << next.severity << ")\n";
                    patientQueue.pop();
                } else {
                    cout << "No patients in queue.\n";
                }
                break;

            case 3:
                if (patientQueue.empty()) {
                    cout << "No patients are waiting.\n";
                } else {
                    cout << "Patients in queue:\n";
                    queue<Patient> temp = patientQueue;
                    while (!temp.empty()) {
                        Patient current = temp.front();
                        cout << current.name << " (Severity: " << current.severity << ")\n";
                        temp.pop();
                    }
                }
                break;

            case 4:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

//Priority queue based on severity of patient
