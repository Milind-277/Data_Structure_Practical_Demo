//Write a program to store first year percentage of students in array. Write function for sorting array of floating-point numbers in ascending order using
    //a. Selection Sort
    //b. Bubble sort
    //c. Insertion Sort and display top five scores.




#include <iostream>
using namespace std;

void selectionSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void displayTopFive(float arr[], int n) {
    cout << "\nTop Five Scores:\n";

    int count = 0;
    for (int i = n - 1; i >= 0 && count < 5; i--) {
        cout << arr[i] << "%\n";
        count++;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    float arr[n];
    cout << "Enter percentages:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;

    do {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        float temp[n];
        for (int i = 0; i < n; i++) temp[i] = arr[i];

        switch (choice) {
            case 1:
                selectionSort(temp, n);
                cout << "\nSorted using Selection Sort:\n";
                for (int i = 0; i < n; i++) cout << temp[i] << " ";
                cout << endl;
                displayTopFive(temp, n);
                break;

            case 2:
                bubbleSort(temp, n);
                cout << "\nSorted using Bubble Sort:\n";
                for (int i = 0; i < n; i++) cout << temp[i] << " ";
                cout << endl;
                displayTopFive(temp, n);
                break;

            case 3:
                insertionSort(temp, n);
                cout << "\nSorted using Insertion Sort:\n";
                for (int i = 0; i < n; i++) cout << temp[i] << " ";
                cout << endl;
                displayTopFive(temp, n);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
