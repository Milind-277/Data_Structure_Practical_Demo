//Write a program for decimal to binary conversion using stack.



#include <iostream>
using namespace std;
#define MAX 50

struct Stack {
    int arr[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack Overflow\n";
        return;
    }
    s.arr[++s.top] = value;
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return s.arr[s.top--];
}

void decimalToBinary(int num) {
    Stack s;
    init(s);

    if (num == 0) {
        cout << "Binary: 0\n";
        return;
    }

    while (num > 0) {
        push(s, num % 2);
        num = num / 2;
    }

    cout << "Binary: ";
    while (!isEmpty(s)) {
        cout << pop(s);
    }
    cout << endl;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    decimalToBinary(decimal);

    return 0;
}
