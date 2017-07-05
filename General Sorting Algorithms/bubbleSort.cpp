// bubble sort algorithm
#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

// an optimized version of bubble sort
void bubbleSort(int A[], int n){
	int i, j;
	bool swapped;
	for(i=0; i<n-1; i++){
		swapped = false;
		for(j=0; j<n-i-1; j++){
			if(A[j] > A[j+1]){
				swap(&A[j], &A[j+1]);
				swapped = true;
			}
		}

		// if no two elements were swapped by inner loop, then break
		if(swapped == false)
			break;
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
	cout<<"Enter the elements\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	bubbleSort(A, size);
	cout<<"The sorted array is\n";
	printArray(A, size);
return 0;
}
