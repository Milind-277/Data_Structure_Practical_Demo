//Write a program to simulate an emergency room where patients are given different priority levels based on the severity of their condition. Use a priority queue to manage the patients, where the most critical patients are treated first.



#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;  

    bool operator < (const Patient &p) const {
        return severity < p.severity;  
        
    }
};

int main() {
    priority_queue<Patient> pq;   
    int choice;

    do {
        cout << "\n--- Emergency Room Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient (Highest Priority)\n";
        cout << "3. View Next Critical Patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Patient p;
                cout << "Enter patient name: ";
                cin >> p.name;
                cout << "Enter severity level (1–10): ";
                cin >> p.severity;

                pq.push(p);
                cout << "Patient added to emergency room!\n";
                break;
            }

            case 2: {
                if (pq.empty()) {
                    cout << "No patients to treat!\n";
                } else {
                    Patient p = pq.top();
                    pq.pop();
                    cout << "Treating patient: " << p.name 
                         << " | Severity: " << p.severity << "\n";
                }
                break;
            }

            case 3: {
                if (pq.empty()) {
                    cout << "No patients waiting.\n";
                } else {
                    Patient p = pq.top();
                    cout << "Next critical patient: " 
                         << p.name << " (Severity: " << p.severity << ")\n";
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
