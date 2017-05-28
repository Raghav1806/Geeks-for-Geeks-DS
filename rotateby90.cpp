// turning a 2D array by 90 degrees

#include<iostream>

using namespace std;

int main(){

int row,column,i,j;
cout<<"Enter row and column of 2D aray\n";
cin>>row>>column;
char A[row][column],B[column][row];
cout<<"Enter the elements of 2D array\n";

for(i=0;i<row;i++)
	for(j=0;j<column;j++)
		cin>>A[i][j];

for(i=0;i<row;i++)
	for(j=0;j<column;j++)
		B[j][row-i] = A[i][j];

cout<<"The rotated 2D array is:\n";
for(i=0;i<column;i++){
	for(j=0;j<row;j++)
		cout<<B[i][j]<<" ";
cout<<"\n";
}

return 0;
}
