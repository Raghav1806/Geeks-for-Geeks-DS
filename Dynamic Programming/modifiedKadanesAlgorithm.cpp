// Finding and printing maximum contiguous subarray sum [even when all elements are negative]

#include <iostream>
using namespace std;

int maxSubArraySum(int A[], int size){

	int maxSoFar = A[0];
	int currMax = A[0];

	for(int i = 1; i < size; i++){
		currMax = max(A[i], currMax + A[i]);
		maxSoFar = max(maxSoFar, currMax);
	}

return maxSoFar;
}

int main(){
	int size, i;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	int maxSum = maxSubArraySum(A, size);
	cout<<"Maximum contiguous sum is "<<maxSum<<"\n";
return 0;
}
