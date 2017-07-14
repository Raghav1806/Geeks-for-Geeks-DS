// Given a binary matrix, find out the maximum size square sub-matrix with all 1s. 

/*
Algorithm:
Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an auxiliary size matrix S[][] in which each entry S[i][j] represents size of the square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost and bottommost entry in sub-matrix.
*/

/*
pseudo code:
1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)	Copy first row and first columns as it is from M[][] to S[][]
     b)	For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
*/

#include <iostream>
using namespace std;

int findMin(int a, int b, int c){
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;
}

int main(){
	int row, column, i, j, max;
	cout<<"Enter the number of rows and columns of matrix\n";
	cin>>row>>column;
	int A[row][column], Abuffer[row][column];
	cout<<"Enter the elements of 2D array\n";

	for(i=0; i<row; i++){
		for(j=0; j<column; j++)
			cin>>A[i][j];
	}

	for(j=0; j<column; j++)
		Abuffer[0][j] = A[0][j];

	for(i=1; i<row; i++){
		for(j=0; j<column; j++){
			if(A[i][j] == 0)
				Abuffer[i][j] = 0;
			else
				Abuffer[i][j] = findMin(Abuffer[i][j-1], Abuffer[i-1][j], Abuffer[i-1][j-1]) + 1;
		}
	}

	cout<<"Buffer matrix is\n";
	for(i=0; i<row; i++){
		for(j=0; j<column; j++)
			cout<<Abuffer[i][j];
	cout<<"\n";
	}

	max = Abuffer[0][0];
	for(i=0; i<row; i++){
		for(j=0; j<column; j++){
			if(max < Abuffer[i][j])
				max = Abuffer[i][j];
		}
	}
cout<<max<<"\n";
return 0;
}



