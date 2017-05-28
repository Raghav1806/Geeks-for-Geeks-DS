// Implementation of Dutch National Flag algorithm
// Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. The functions should put all 0s first, then all 1s and all 2s in last.

#include<iostream>

using namespace std;

int main(){

int size,low,mid,high,i,temp;
cout<<"Enter the size of array\n";
cin>>size;
int A[size];
cout<<"Enter elements of array\n";

for(i=0;i<size;i++)
cin>>A[i];

low = mid = 0;
high = size-1;

	while(mid <= high){
		if(A[mid] == 0){
			temp = A[low];
			A[low] = A[mid];
			A[mid] = temp;
			mid++;
			low++;	
		}
		else if(A[mid] == 1)
			mid++;
		else if(A[mid] == 2){
			temp = A[mid];
			A[mid] = A[high];
			A[high] = temp;
			high--;
		}
	}

cout<<"The sorted array is: ";
for(i=0;i<size;i++)
cout<<A[i]<<" ";

cout<<"\n";
return 0;
}
