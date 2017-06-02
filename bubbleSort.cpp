// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

#include<iostream>

using namespace std;

int main(){
int size,i,j,temp;
cout<<"Enter size of array to be sorted\n";
cin>>size;
int A[size];
cout<<"Enter the elements to be sorted\n";
	for(i=0;i<size;i++)
		cin>>A[i];

	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}

cout<<"The sorted array is\n";
for(i=0;i<size;i++)
	cout<<A[i]<<" ";
cout<<"\n";
return 0;
}
