//Write a menu driven program using arrays to create a system to store and manage marks for a set of students.
    //a. Use an array to store student marks for different subjects for a given class of students.
    //b. Calculate the total marks, average marks, and the highest/lowest marks for each student.
    //c. Display Topper student.



#include <iostream>
using namespace std;

struct student{
    string name;
    int marks[10];
    int total,average,highest,lowest;
};

void inputmarks(student students[], int &n, int &m){
    cout <<"Enter the number of students :";
    cin >> n;
    cout <<"Enter the number of subjects :";
    cin >> m;
    for(int i=0; i<n; i++){
        cout <<"\n Enter the Name of Student " <<i+1 <<":";
        cin >> students[i].name;
        students[i].total=0;
        students[i].highest=0;
        students[i].lowest=999;
        
        for(int j=0; j<m; j++){
            cout <<"\n Enter the Marks of subject" <<j+1 <<":";
            cin >> students[i].marks[j];
            students[i].total+=students[i].marks[j];
            if(students[i].marks[j] > students[i].highest)
                students[i].highest = students[i].marks[j];
            if(students[i].marks[j] < students[i].lowest)
                students[i].lowest = students[i].marks[j];
        }
        students[i].average = (float)students[i].total/m;
    }
}

void displaystudentdata(student students[], int n, int m){
    cout <<"\n Student Data :\n";
    for(int i=0; i<n; i++){
        cout <<"\n Name:" <<students[i].name << endl;
        cout <<" \n Marks:";
        for(int j=0; j<m; j++){
            cout << students[i].marks[j] <<" ";
        }
        cout <<"\n Total =" << students[i].total;
        cout <<"\n Average =" << students[i].average;
        cout <<"\n Highest =" << students[i].highest;
        cout <<"\n Lowest =" << students[i].lowest <<endl;
    }
}

void displaytopper(student students[], int n){
    int topperindex=0;
        for(int i=1; i<n; i++){
            if(students[i].total > students[topperindex].total){
                topperindex=i;
            }
}
    cout <<"\n Topper Student :" <<students[topperindex].name <<endl;
    cout <<"\n Topper Marks :" <<students[topperindex].total <<endl;
    cout <<"\n Average Marks :" <<students[topperindex].average <<endl;
}

int main(){
    student students[100];
    int n=0, m=0;
    int choice;
    
    do{
        cout <<"\n Menu :\n";
        cout <<"1.Input Marks :\n";
        cout <<"2. Display Student data :\n";
        cout <<"3. Display Topper Students  :\n";
        cout <<"4. Exit :\n";
        cout <<"Enter your choice (1-4) :\n";
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputmarks(students, n, m);
                break;
            case 2:
                if(n>0)
                    displaystudentdata(students, n, m);
                else
                    cout <<"No data available. Please input marks first \n";
                break;
            case 3:
                if(n>0)
                    displaytopper(students, n);
                else
                    cout <<"No data available. Please input marks first \n";
                break;
            case 4:
                cout <<"Exiting program. \n";
                break;
                default:
                    cout <<"Invalid choice. Please Try Again.\n";
        }
    }   while(choice !=4);
    
    return 0;
}