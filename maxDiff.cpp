// Find Maximum difference between two elements such that larger element appears after the smaller number, assuming all elements are +ve

#include<iostream>
#include<cmath>

using namespace std;

int main(){
int size,max,i,maxDiff,diff;
maxDiff = 0;

cout<<"Enter size of array\n";
cin>>size;
int A[size];

cout<<"Enter elements of array\n";
	for(i=0;i<size;i++)
		cin>>A[i];

max = A[size-1];

	for(i=size-2;i>=0;i--){

		diff = abs(A[i]-max);
		if(A[i] > max)
			max = A[i];
		
	if(diff > maxDiff)
			maxDiff = diff;
	}		

cout<<maxDiff<<"\n";
return 0;
}
