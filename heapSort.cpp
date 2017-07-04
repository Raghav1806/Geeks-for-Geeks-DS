// program for implementation of heap sort
// max heap is used in this question
#include <iostream>
using namespace std;

// to heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i){
	int largest = i;	// initialise largest as root
	int l = 2*i + 1;
	int r = 2*i + 2;

	// if left child is larger than root
	if(l < n && arr[l] > arr[largest])
		largest = l;

	// if right child is larger than largest so far
	if(r < n && arr[r] > arr[largest])
		largest = r;

	// if largest is not root
	if(largest != i){
		swap(arr[i], arr[largest]);
		
		// recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	// build heap (rearrange array)
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// one by one extract an element from heap
	for(int i = n-1; i >= 0; i--){
		// move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
cout<<"\n";
}

int main(){
	int size, i;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[i];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];

	heapSort(A, size);

	cout<<"Sorted array is\n";
	printArray(A, size);

return 0;
}
