//  An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader
// All elements of array are considered positive

#include<iostream>

using namespace std;

int main(){
int size,i,max,index;
index = 1;

cout<<"Enter the size of array ";
cin>>size;

int A[size];

cout<<"Enter the elements of array\n";
for(i=0;i<size;i++)
cin>>A[i];

max = -1;

for(i=size-1;i>=0;i--){
	if(max < A[i]){
		max = A[i];
		cout<<max<<" ";	
	}
}
cout<<"\n";
return 0;
}
