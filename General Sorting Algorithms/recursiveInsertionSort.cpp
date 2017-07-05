// recursive insertion sort program

#include <iostream>
using namespace std;

void insertionSort(int A[], int n){
	// base case
	if(n <= 1)
		return;

	// sort first n-1 elements
	insertionSort(A, n-1);

	// insert last element at its correct position
	int last = A[n-1];
	int j = n-2;

	// move elements of A[], that are greater than key, to one position ahead of their current position
	while(j >= 0 && A[j] > last){
		A[j+1] = A[j];
		j--;
	}
	A[j+1] = last;
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
	cout<<"Enter elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	insertionSort(A, size);
	cout<<"The sorted array is\n";
	printArray(A, size);

return 0;
}
