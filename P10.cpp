//Write a program to simulate a customer service desk using a queue to manage customer tickets.



#include <iostream>
using namespace std;
#define MAX 50

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int ticket) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more customers.\n";
            return;
        }
        if (front == -1)
            front = 0;  

        arr[++rear] = ticket;
        cout << "Customer Ticket " << ticket << " added to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }

        cout << "Serving Customer Ticket " << arr[front] << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }

        cout << "\nCustomers Waiting in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "Ticket " << arr[i] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, ticketNo = 1;

    do {
        cout << "\n--- Customer Service Desk Menu ---\n";
        cout << "1. Add Customer Ticket\n";
        cout << "2. Serve Next Customer\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q.enqueue(ticketNo++);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
