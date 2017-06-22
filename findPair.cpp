// Given an array A[] and a number x, check for pair in A[] with sum as x [All elements are considered +ve]

/* 
Algorithm:
1) Initialize Binary Hash Map M[] = {0, 0, ...}
2) Do following for each element A[i] in A[]
   (a)	If M[x - A[i]] is set then print the pair (A[i], x - A[i])
   (b)	Set M[A[i]]
*/

#include <iostream>
#define MAX 100000
using namespace std;

void printPairs(int A[], int size, int sum){
	int i, temp;
	bool binMap[MAX] = {0};
	
	for(i = 0; i < size; i++){
		temp = sum-A[i];
		if(temp >= 0 && binMap[temp] == 1)
			cout<<"Pair with given sum is "<<A[i]<<", "<<temp<<"\n";
	binMap[A[i]] = 1;
	} 
}

int main(){
	int size, i, sum;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	cout<<"Enter the required sum\n";
	cin>>sum;
	printPairs(A, size, sum);
return 0;
}
