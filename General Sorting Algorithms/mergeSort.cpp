// Merge Sort program

/*
Algorithm:
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/

#include <iostream>
using namespace std;

// merge two subarrays of A[]
// first subarray is A[l..m]
// second subarray is A[m+1..r]

void merge(int A[], int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;

	// create temp array
	int L[n1], R[n2];
	
	// copy data to temp arrays L[] & R[]
	for(i=0; i<n1; i++)
		L[i] = A[l+i];
	for(j=0; j<n2; j++)
		R[j] = A[m+l+j];

	// merge the temp arrays back into A[l..r]
	i = 0;	// initial index of first subarray
	j = 0; 	// initial index of second subarray
	k = l;	// initial index of merged subarray

	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	// copy the remaining elements of L[], if any
	while(i < n1){
		A[k] = L[i];
		i++;
		k++;
	}

	// copy the remaining elements of R[], if any
	while(j < n2){
		A[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is right index of sub array of A to be sorted
void mergeSort(int A[], int l, int r){
	if(l < r){
		// same as (l+r)/2, but avoids overflow for large l & r
		int m = l+(r-l)/2;

		// sort first and second halves
		mergeSort(A, l, m);
		mergeSort(A, m+1, r);

		merge(A, l, m, r);
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
	mergeSort(A, 0, size-1);

	cout<<"Sorted array is\n";
	printArray(A, size);

return 0;
}
