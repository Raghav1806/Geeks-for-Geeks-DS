// selection sort program
// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 

#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int A[], int n){
	int i, j, minIndex;

	// one by one ove boundary of unsorted subarray
	for(i=0; i<n-1; i++){
		// find the minimum element in unsorted array
		minIndex = i;
		for(j=i+1; j<n; j++)
			if(A[j] < A[minIndex])
				minIndex = j;

		// swap the found minimum element with ith element
		swap(&A[minIndex], &A[i]);
	}
}

void printArray(int A[], int size){
	int i;
	for(i=0; i<size; i++)
		cout<<A[i]<<" ";
cout<<"\n";
}

int main(){
	int i, size;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	
	selectionSort(A, size);

	cout<<"The sorted array is\n";
	printArray(A, size);

return 0;
}
