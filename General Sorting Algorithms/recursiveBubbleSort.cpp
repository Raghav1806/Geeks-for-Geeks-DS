// recursive bubble sort algorithm

#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int A[], int n){
	// base case
	if(n == 1)
		return;

	// one pass of bubble sort. After this pass, the largest element is moved (or bubbled) to end.
	for(int i=0; i<n-1; i++)
		if(A[i] > A[i+1])
			swap(A[i], A[i+1]);

	// largest element is fixed, recur for remaining array
	bubbleSort(A, n-1); 
}

void printArray(int A[], int n){
	for(int i=0; i<n; i++)
		cout<<A[i]<<" ";
cout<<"\n";
}

int main(){
	int i, size;
	cout<<"Enter size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	bubbleSort(A, size);
	cout<<"The sorted array is\n";
	printArray(A, size);
return 0;
}
