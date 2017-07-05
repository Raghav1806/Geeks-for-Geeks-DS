// insertion sort program
#include <iostream>
using namespace std;

void insertionSort(int A[], int n){
	int i, key, j;
	for(i=1; i<n; i++){
		key = A[i];
		j = i-1;

		while(j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

void printArray(int A[], int n){
	int i;
	for(i=0; i<n; i++)
		cout<<A[i]<<" ";
cout<<"\n";
}

int main(){
	int size, i;
	cout<<"Enter size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];

	insertionSort(A, size);
	cout<<"Sorted array is\n";
	printArray(A, size);

return 0;
}
