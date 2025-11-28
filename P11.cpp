//Write a program to check whether a given string is a palindrome using a deque.



#include <iostream>
using namespace std;
#define MAX 100

class Deque {
    char arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertRear(char x) {
        if (isFull()) {
            cout << "Deque Overflow!\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    char deleteFront() {
        if (isEmpty()) return '\0';

        char x = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
        return x;
    }

    char deleteRear() {
        if (isEmpty()) return '\0';

        char x = arr[rear];

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
        return x;
    }
};

bool isPalindrome(string s) {
    Deque dq;

    for (char c : s) {
        if (c != ' ')          
            dq.insertRear(c);
    }

    while (!dq.isEmpty()) {
        char left = dq.deleteFront();
        char right = dq.deleteRear();

        if (left != right)
            return false;

        if (dq.isEmpty())
            break;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str))
        cout << "It is a Palindrome.\n";
    else
        cout << "It is NOT a Palindrome.\n";

    return 0;
}
