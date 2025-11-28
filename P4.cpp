//Write a menu driven program to perform String Operations without Library Functions.
    //a. Calculate Length of string
    //b. Concatenate two strings
    //c. Reverse a String
    //d. Check whether given string is Palindrome or not



#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void stringConcat(char str1[], char str2[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);

    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
}

void stringReverse(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

bool isPalindrome(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main() {
    char str1[100], str2[100];
    int choice;

    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Length of String\n";
        cout << "2. Concatenate Two Strings\n";
        cout << "3. Reverse a String\n";
        cout << "4. Check Palindrome\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                cout << "Length = " << stringLength(str1) << endl;
                break;

            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                stringConcat(str1, str2);
                cout << "Concatenated String = " << str1 << endl;
                break;

            case 3:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                stringReverse(str1);
                cout << "Reversed String = " << str1 << endl;
                break;

            case 4:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                if (isPalindrome(str1))
                    cout << "It is a Palindrome.\n";
                else
                    cout << "It is NOT a Palindrome.\n";
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
