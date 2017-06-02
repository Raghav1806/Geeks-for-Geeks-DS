// Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.

#include<iostream>

using namespace std;

int main(){
int size,i,j,key;
cout<<"Enter size of array to be sorted\n";
cin>>size;
int A[size];
cout<<"Enter elements of array\n";
	for(i=0;i<size;i++)
		cin>>A[i];

	for(i=1;i<size;i++){
		key = A[i];
		j = i-1;

		while(j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}

cout<<"The sorted array is\n";
for(i=0;i<size;i++)
	cout<<A[i]<<" ";

cout<<"\n";
return 0;
}
