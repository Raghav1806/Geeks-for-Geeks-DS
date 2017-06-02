// Selection Sort algorithm

// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.

#include<iostream>

using namespace std;

int main(){
int size,i,j,minIndex,temp;
cout<<"Enter the size of array to be sorted\n";
cin>>size;
int A[size];
cout<<"Enter the elements of array\n";

	for(i=0;i<size;i++)
		cin>>A[i];

	for(i=0;i<size-1;i++){
		minIndex = i;
		for(j=i+1;j<size;j++){
			if(A[j] < A[minIndex])
				minIndex = j;
		}	
		temp = A[i];
		A[i] = A[minIndex];
		A[minIndex] = temp;
	}

cout<<"The sorted array is:\n";
for(i=0;i<size;i++)
	cout<<A[i]<<" ";
cout<<"\n";
return 0;
}

