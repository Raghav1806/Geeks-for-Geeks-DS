// implementing kadane's algorithm for maximum contiguous subarray sum [for +ve answer]

#include <iostream>
using namespace std;

int main(){
	int size, i, maxSoFar, maxEndingHere;
	maxSoFar = maxEndingHere = 0;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";

	for(i=0; i<size; i++)
		cin>>A[i];

	for(i=0; i<size; i++){
		maxEndingHere += A[i];
		if(maxEndingHere < 0)
			maxEndingHere = 0;
		if(maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}

	cout<<"Maximum subarray sum is: "<<maxSoFar<<"\n";

return 0;
}
