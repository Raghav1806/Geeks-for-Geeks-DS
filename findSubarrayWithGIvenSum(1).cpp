// Find subarray with given sum [Non Negative numbers]

#include <iostream>
using namespace std;

int subArraySum(int A[], int n, int sum){
	int currSum = A[0], start = 0, i;
	// add elements one by one to currSum and if currSum exceeds sum, remove startin elements
	for(i=1; i<=n; i++){
		while(currSum > sum && start < i-1){
			currSum -= A[start];
			start++;
		}

		if(currSum == sum){
			cout<<"Sum found between "<<start<<" "<<i-1<<"\n";
			return 1;
		}
		if(i < n)
			currSum += A[i];
	}
cout<<"No subarray found\n";
return 0;
}

int main(){
	int size, i, sum;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	cout<<"Enter the value of desired sum\n";
	cin>>sum;
	
	subArraySum(A, size, sum);	

return 0;
}
