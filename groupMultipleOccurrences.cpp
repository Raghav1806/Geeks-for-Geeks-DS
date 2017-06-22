// Given an unsorted array with repetitions, the task is to group multiple occurrence of individual elements. The grouping should happen in a way that the order of first occurrences of all elements is maintained.

#include <iostream>
using namespace std;

int main(){
	int size, i;
	cout<<"Enter size of array";
	cin>>size;
	int A[size], Hash[size];
	for(i=0; i<size; i++)
		Hash[i] = 0;
	cout<<"Enter elements of array\n";
	for(i=0; i<size; i++){
		cin>>A[i];
		Hash[A[i]]++;
	}
	for(i=0; i<size; i++){
		if(Hash[A[i]] > 0){
			while(Hash[A[i]] != 0){			
			cout<<A[i]<<" ";
			Hash[A[i]]--;
			}
		}
	}
cout<<"\n";
return 0;
}
