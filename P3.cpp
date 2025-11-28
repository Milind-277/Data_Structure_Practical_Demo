//Write a menu-driven program that allows the user to perform the following set operations using 1D arrays with pointers:
    //a. Union
    //b. Intersection
    //c. Difference
    //d. Symmetric Difference
    //e. Subset




#include <iostream>
using namespace std;

const int MAX = 100;
int A[MAX], B[MAX], sizeA, sizeB;

class setoperation {
    
    public:
        void getdata() {
            cout << "Enter the number of elements in Set A : ";
            cin >> sizeA;
            cout << "Enter the elements of Set A :\n";
            for (int i=0; i<sizeA; i++)
                cin >> A[i];
                
            cout << "Enter the number of elements in Set B : ";
            cin >> sizeB;
            cout << "Enter the elements of Set B :\n";
            for (int i=0; i<sizeB; i++)
                cin >> B[i];
        }
        
        bool isPresent(int arr[], int size, int element) {
            for (int i=0; i<size; i++){
                if (arr[i]==element)
                    return true;
            }
            return false;
        }
        
        void unionSet(int A[], int B[], int sizeA, int sizeB) {
            cout << "Union : ";
            for (int i=0; i<sizeA; i++)
                cout << A[i] <<" ";
                
            for (int i=0; i<sizeB; i++) {
                if (!isPresent(A, sizeA, B[i]))
                    cout << B[i] <<" ";
            }
        cout <<endl;
        }
        
        void intersectionSet(int A[], int B[], int sizeA, int sizeB) {
            cout << "Intersection : ";
            for (int i=0; i< sizeA; i++) {
                if (isPresent(B, sizeB, A[i]))
                    cout << A[i] << " ";
            }
            cout << endl;
        }
        
        void differenceSet(int A[], int B[], int sizeA, int sizeB) {
            cout << "Present in A but not in B : ";
            for (int i=0; i< sizeA; i++) {
                if (!isPresent(B, sizeB, A[i]))
                    cout << A[i] << " ";
            }
            cout << endl;
        }
        
        void symmetricDifferenceSet(int A[], int B[], int sizeA, int sizeB) {
            cout << "Symmetric Difference : ";
            for (int i=0; i< sizeA; i++) {
                if (!isPresent(B, sizeB, A[i]))
                    cout << A[i] << " ";
            }
            
            for (int i=0; i< sizeB; i++) {
                if (!isPresent(A, sizeA, B[i]))
                    cout << B[i] << " ";
            }
            cout << endl;
        }
        
        void checkSubset(int A[], int B[], int sizeA, int sizeB) {
            bool isSubset = true;
            for (int i=0; i< sizeA; i++) {
                if (!isPresent(B, sizeB, A[i])) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
                cout << "A is a subset of B" <<endl;
            else
                cout << "A is NOT a subset of B" <<endl;
            cout << endl;
        }
        
};

int main() {
    int choice;
    setoperation S;
    S.getdata();
    
    do {
        cout << "\n ===== MENU =====\n";
        cout << "1. Union\n";
        cout << "2. Intersection\n";
        cout << "3. Difference (A - B)\n";
        cout << "4. Symmetric Difference\n";
        cout << "5. Check if A is Subset of B\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                S.unionSet(A, B, sizeA, sizeB);
            break;
            
            case 2:
                S.intersectionSet(A, B, sizeA, sizeB);
            break;
            
            case 3:
                S.differenceSet(A, B, sizeA, sizeB);
            break;
            
            case 4:
                S.symmetricDifferenceSet(A, B, sizeA, sizeB);
            break;
            
            case 5:
                S.checkSubset(A, B, sizeA, sizeB);
            break;
            
            case 6:
                cout << "Exiting Program...\n";
            break;
            
            default:
                cout << "Invalid choice. Please Try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}
