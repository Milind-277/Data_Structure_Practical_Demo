//Write a menu-driven program that allows the user to perform the following matrix (3x3) operations using 2D arrays:
    //a. Matrix Addition
    //b. Matrix Subtraction
    //c. Matrix Multiplication
    //d. Transpose of a matrix



#include <iostream>
using namespace std;

int A[3][3],B[3][3];

class matrixoperation
{
  public:
  
 void inputMatrix(int matrix[3][3],const string& name)
 {
 cout<<"Enter elements for matrix "<< name << " 3*3 :\n";
 for(int i=0;i<3;++i)
   for(int j=0;j<3;++j)
    cin>>matrix[i][j];
 }
 
 void displayMatrix(int matrix[3][3])
  {
 for(int i=0;i<3;++i)
 {
 
   for(int j=0;j<3;++j)
    {	  
    cout<<"\t" << matrix[i][j];
    }
   cout<<"\n";
   }
  }
  

 
 void addMatrices(int A[3][3],int B[3][3])
 {
 int result[3][3];
 cout<<"Matrix Addition Result: "<<"\n";
 for(int i=0;i<3;++i)
   for(int j=0;j<3;++j)
     result[i][j]=A[i][j]+B[i][j];
   displayMatrix(result);
 }
 
 void subtractMatrices(int A[3][3],int B [3][3])
 {
 int result[3][3];
 cout<<"Matrix Substraction Result: "<<endl;
 for(int i=0;i<3;++i)
   for(int j=0;j<3;++j)
     result[i][j]=A[i][j]-B[i][j];
 displayMatrix(result);
 }
 
 void multiplyMatrices(int A [3][3], int B [3][3])
 {
 int result[3][3];
 cout<<"Matrix Multiplication Result:"<<endl;
 for(int i=0;i<3;++i)
   for(int j=0;j<3;++j)
     result[i][j]=A[i][j]*B[i][j];
 displayMatrix(result);
 }
 
 void transposeMatrices(int A [3][3], int B [3][3])
 {
 int transposed[3][3];
 cout<<"Transposed of Matrix A:"<<endl;
 for(int i=0;i<3;++i)
   for(int j=0;j<3;++j)
     transposed[j][i]=A[i][j];
 displayMatrix(transposed);
 }
 
}; 

int main()
{
//int A[3][3],B[3][3];

  int choice;
  matrixoperation object;
  
  object.inputMatrix(A,"A");
  object.inputMatrix(B,"B");
  
  do
  {
  cout<<"\n== Matrix Operations Menu=="<<endl;
  cout<<"1. Addition (A+B)"<<endl;
  cout<<"2. Substraction (A-B)"<<endl;
  cout<<"3. Multiplication (A*B)"<<endl;
  cout<<"4. Transpse of Matrix A"<<endl;
  cout<<"5. Exit\n"<<endl;
  cout<<"Enter your Choice(1-5): "<<endl;
  cin>>choice;
  
  
  switch(choice)
  {
  case 1:
     object.addMatrices(A,B);
    break;

 case 2:
     object.subtractMatrices(A,B);
     break;


 case 3:
     object.multiplyMatrices(A,B);
     break;

 case 4:
     object.transposeMatrices(A,B);
     break;
     
 case 5:
     cout<<"Exiting program.\n";
     break;
 defult:
 cout<<"Invalid choice! try again.\n";
 
 }
}while(choice!=5);

return 0;
}
