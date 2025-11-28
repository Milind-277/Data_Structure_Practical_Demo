//Implement stack as an abstract data type and use this ADT for conversion of:
    //a. Infix to postfix expression
    //b. Infix to prefix expression
    //c. Evaluation of postfix expression
    //d. Evaluation of prefix expression




#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == SIZE - 1; }
    bool isEmpty() { return top == -1; }

    void push(char x) {
        if (!isFull()) arr[++top] = x;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

class IntStack {
    int arr[SIZE];
    int top;

public:
    IntStack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int x) { arr[++top] = x; }

    int pop() { return arr[top--]; }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            st.pop(); 
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                postfix += st.pop();
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

string reverseString(string s) {
    string r = "";
    for (int i = s.length() - 1; i >= 0; i--)
        r += s[i];
    return r;
}

string replaceBrackets(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    return s;
}

string infixToPrefix(string infix) {
    string rev = reverseString(infix);
    rev = replaceBrackets(rev);
    string post = infixToPostfix(rev);
    return reverseString(post);
}

int evalPostfix(string exp) {
    IntStack st;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int b = st.pop();
            int a = st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    return st.pop();
}

int evalPrefix(string exp) {
    IntStack st;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int a = st.pop();
            int b = st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }

    return st.pop();
}

int main() {
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "\nPostfix: " << postfix;
    cout << "\nPrefix: " << prefix;

    cout << "\nPostfix Evaluation: " << evalPostfix(postfix);
    cout << "\nPrefix Evaluation: " << evalPrefix(prefix);

    cout << endl;
    return 0;
}
