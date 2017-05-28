// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k. Assuming positive elements.

#include<iostream>

using namespace std;

int main(){
int size,i,k,max;
max = 0;
cout<<"Enter size of array:\n";
cin>>size;
int A[size];
cout<<"Enter the value of k:\n";
cin>>k;
cout<<"Enter elements of array:\n";
for(i=0;i<size;i++)
cin>>A[i];

for(i=0;i<k;i++)
	if(A[i] > max)
		max = A[i];

cout<<max<<" ";

for(i=k;i<size;i++){
	if(A[i] > max)
		max = A[i];
cout<<max<<" ";
}
cout<<"\n";	

return 0;
}
