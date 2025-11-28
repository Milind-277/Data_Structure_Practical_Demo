//Implement Circular Queue. Perform following operations on it.
    //a. Insertion (Enqueue)
    //b. Deletion (Dequeue)
    //c. Display (forward and reverse)




#include <iostream>
using namespace std;

#define MAX 50

class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % MAX);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }

        if (front == -1) {      
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;

        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) {   
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void displayForward() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue (Forward): ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void displayReverse() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Queue (Reverse): ";
        int i = rear;
        while (true) {
            cout << arr[i] << " ";
            if (i == front) break;
            i = (i - 1 + MAX) % MAX;  
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Reverse\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.displayForward();
                break;

            case 4:
                q.displayReverse();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
