// Implementation of Moore's Voting algorithm, used to find if their exists any element which occurs majority of times in an array

#include<iostream>

using namespace std;

int main(){

int size,i,count,majorityElement;
count = 0;
cout<<"Enter the number of elements\n";
cin>>size;
int A[size];
cout<<"Enter the elements\n";

	for(i=0;i<size;i++)
	cin>>A[i];

majorityElement = A[0];
count = 1;

for(i=1;i<size;i++){
	if(A[i] == majorityElement)
		count++;
	else
		count--;

	if(count == 0){
		majorityElement = A[i];
		count = 1;
	}
}

if(count > 0)
cout<<"Majority element is "<<majorityElement<<"\n";
else
cout<<"No majority element exists\n";
return 0;
}

