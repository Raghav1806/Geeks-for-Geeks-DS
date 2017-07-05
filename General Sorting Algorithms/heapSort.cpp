// heap sort algorithm

#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int A[], int n, int i){
	int largest = i;	// initialize largest as root
	int l = 2*i + 1;	
	int r = 2*i + 2;

	// if left child is larger than root
	if(l < n && A[l] > A[largest])
		largest = l;
	// if right child is larger than largest so far
	if(r < n && A[r] > A[largest])
		largest = r;

	// if largest is not root
	if(largest != i){
		swap(A[i], A[largest]);

		// recursively heapify the affected sub-tree
		heapify(A, n, largest);
	} 
}

// main function to do heap sort
void heapSort(int A[], int size){
	// build heap (rearrange array)
	for(int i = size/2 - 1; i >= 0; i--)
		heapify(A, size, i);

	// one by one extract element from heap
	for(int i = size-1; i >= 0; i--){
		// move current root to end
		swap(A[0], A[i]);

		// call max heapify on the reduced heap
		heapify(A, i, 0);
	}
}

void printArray(int A[], int size){
	for(int i=0; i<size; i++)
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

	heapSort(A, size);

	cout<<"Sorted array is\n";
	printArray(A, size);

return 0;
}
