// quick sort program
#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller than pivot elements to left of pivot and all greater elements to right of pivot
*/

int partition(int A[], int low, int high){
	int pivot = A[high];
	int i = (low-1);

	for(int j = low; j <= high-1; j++){
		// if current element is smaller than or equal to pivot
		if(A[j] <= pivot){
			i++;	// increment index of smaller element
			swap(&A[i], &A[j]);
		}
	}

	swap(&A[i+1], &A[high]);
	return i+1;
}

/* The main function that implements quick sort
	A[] -> array to be sorted
	low -> starting index
	high -> ending index
*/
void quickSort(int A[], int low, int high){
	if(low < high){
		// pi is partitioning index
		int pi = partition(A, low, high);

		// separately sort elements before partition and after partition
		quickSort(A, low, pi-1);
		quickSort(A, pi+1, high);
	}
}

void printArray(int A[], int size){
	int i;
	for(i=0; i<size; i++)
		cout<<A[i]<<" ";
cout<<"\n";
}

int main(){
	int size, i;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];

	quickSort(A, 0, size-1);

	cout<<"The sorted array is\n";
	printArray(A, size);

return 0;
}
