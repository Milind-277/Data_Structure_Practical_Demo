//Write a program to store roll numbers of student in array who attended training program in random order. Write function for searching whether particular student attended training program or not, using Linear search and Binary Search.



#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  
    }
    return -1; 
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of students: ";
    cin >> n;

    int arr[n];
    cout << "Enter roll numbers (random order):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nEnter roll number to search: ";
    cin >> key;

    int pos1 = linearSearch(arr, n, key);
    if (pos1 != -1)
        cout << "\nLinear Search: Student attended (found at index "
             << pos1 << ").\n";
    else
        cout << "\nLinear Search: Student did NOT attend.\n";

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int pos2 = binarySearch(arr, n, key);
    if (pos2 != -1)
        cout << "Binary Search: Student attended (found at sorted index "
             << pos2 << ").\n";
    else
        cout << "Binary Search: Student did NOT attend.\n";

    return 0;
}
