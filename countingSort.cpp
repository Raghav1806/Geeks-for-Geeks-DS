// counting sort for integers form 0-100

#include<iostream>

using namespace std;

int main(){
int size,i;
cout<<"Enter the size of array to be sorted\n";
cin>>size;
int A[size],count[100];

	for(i=0;i<100;i++)
		count[i] = 0;

cout<<"Enter the elements of array\n";

	for(i=0;i<size;i++){
		cin>>A[i];
		count[A[i]]++;
	}

cout<<"The sorted array is\n";

	for(i=0;i<100;i++){
		while(count[i] > 0){
			count[i]--;			
			cout<<i<<" ";
		}
	}

cout<<"\n";
return 0;
}
