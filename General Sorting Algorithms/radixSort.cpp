// Radix Sort program

#include <iostream>
using namespace std;

// a utility function to get maximum value in A[]
int getMax(int A[], int n){
	int ans = A[0];
	for(int i = 0; i<n; i++)
		if(A[i] > ans)
			ans = A[i];
return ans;
}

// a function to do counting sort of A[] according to the digit represented by exp.
void countSort(int A[], int n, int exp){
	int output[n];	// output array
	int i;
	int count[10] = {0};

	// store count of occurrences in count[]
	for(i=0; i<n; i++)
	count[(A[i]/exp)%10]++;

	// change count[i] so that count[i] now contains actual position of this digit in output[]
	for(i=1; i<10; i++)
		count[i] += count[i-1];

	// build the output array
	for(i=n-1; i >= 0; i--){
		output[count[(A[i]/exp)%10]-1] = A[i];
		count[(A[i]/exp)%10]--;
	}

	// copy the output array to A[], so that A[] now contains sorted numbers according to current digit
	for(i=0; i<n; i++)
		A[i] = output[i];
}

// the main function that sorts A[] using Radix Sort
void radixSort(int A[], int size){
	
	// find maximum number to know number of digits
	int m = getMax(A, size);

	// do counting sort for each digit
	for(int exp = 1; m/exp > 0; exp *= 10)
		countSort(A, size, exp);
}

void printArray(int A[], int size){
	for(int i = 0; i<size; i++)
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
	radixSort(A, size);
	cout<<"The sorted array is\n";
	printArray(A, size);
return 0;
}
