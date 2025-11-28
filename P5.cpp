//Write a menu driven that depicts the working of a library. The menu options should be:
    //1. Add book information
    //2. Display book information
    //3. Search a Particular book
    //4. Modify Book Information
    //5. List the title of specified book
    //6. List the count of books in the library
    //7. Exit
//Create a singly linked list structure called library to hold accession number, title of the book, author name, price of the book, and flag indicating whether book is issued or not.




#include <iostream>
#include <cstring>
using namespace std;

struct Library {
    int accNo;                  
    char title[50];
    char author[50];
    float price;
    bool issued;                
    Library *next;
};

Library *head = NULL;

void addBook() {
    Library *newBook = new Library;
    
    cout << "Enter Accession Number: ";
    cin >> newBook->accNo;
    cin.ignore();

    cout << "Enter Book Title: ";
    cin.getline(newBook->title, 50);

    cout << "Enter Author Name: ";
    cin.getline(newBook->author, 50);

    cout << "Enter Book Price: ";
    cin >> newBook->price;

    cout << "Is Book Issued? (1 = Yes, 0 = No): ";
    cin >> newBook->issued;

    newBook->next = NULL;

    // Insert at end
    if (head == NULL)
        head = newBook;
    else {
        Library *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
    }

    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {
    if (head == NULL) {
        cout << "No books in library.\n";
        return;
    }

    Library *temp = head;
    cout << "\n--- Library Books ---\n";
    while (temp != NULL) {
        cout << "\nAcc No: " << temp->accNo;
        cout << "\nTitle: " << temp->title;
        cout << "\nAuthor: " << temp->author;
        cout << "\nPrice: " << temp->price;
        cout << "\nIssued: " << (temp->issued ? "Yes" : "No");
        cout << "\n-----------------------";
        temp = temp->next;
    }
    cout << endl;
}

Library* searchBook(int acc) {
    Library *temp = head;
    while (temp != NULL) {
        if (temp->accNo == acc)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void modifyBook() {
    int acc;
    cout << "Enter Accession Number to Modify: ";
    cin >> acc;

    Library *book = searchBook(acc);

    if (book == NULL) {
        cout << "Book Not Found!\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Title: ";
    cin.getline(book->title, 50);

    cout << "Enter New Author: ";
    cin.getline(book->author, 50);

    cout << "Enter New Price: ";
    cin >> book->price;

    cout << "Is Book Issued? (1 = Yes, 0 = No): ";
    cin >> book->issued;

    cout << "\nBook Information Updated!\n";
}

void listTitle() {
    int acc;
    cout << "Enter Accession Number: ";
    cin >> acc;

    Library *book = searchBook(acc);

    if (book == NULL) {
        cout << "Book Not Found!\n";
        return;
    }

    cout << "Title of Book: " << book->title << endl;
}

void countBooks() {
    int count = 0;
    Library *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total Number of Books in Library: " << count << endl;
}


int main() {
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book Information\n";
        cout << "2. Display Book Information\n";
        cout << "3. Search a Particular Book\n";
        cout << "4. Modify Book Information\n";
        cout << "5. List the Title of Specified Book\n";
        cout << "6. List Count of Books\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: {
                int acc;
                cout << "Enter Accession Number: ";
                cin >> acc;
                Library *b = searchBook(acc);
                if (b)
                    cout << "Book Found: " << b->title << " by " << b->author << endl;
                else
                    cout << "Book Not Found!\n";
                break;
            }
            case 4: modifyBook(); break;
            case 5: listTitle(); break;
            case 6: countBooks(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}
