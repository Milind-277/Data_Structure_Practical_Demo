//Implement Circular Linked List. Perform following operations on it.
    //a. Insertion
    //b. Deletion
    //c. Display



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  
    }

    cout << "Node Inserted.\n";
}

void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *current = head;
    Node *previous = NULL;

    if (head->data == value) {

        if (head->next == head) {
            delete head;
            head = NULL;
            cout << "Node Deleted.\n";
            return;
        }

        Node *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        Node *del = head;
        head = head->next;
        delete del;

        cout << "Node Deleted.\n";
        return;
    }

    do {
        previous = current;
        current = current->next;

        if (current->data == value) {
            previous->next = current->next;
            delete current;
            cout << "Node Deleted.\n";
            return;
        }
    } while (current != head);

    cout << "Value not found in list.\n";
}

void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                displayList();
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
