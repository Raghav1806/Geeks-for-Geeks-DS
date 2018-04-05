// Given an array find longest increasing subsequence in this array
#include <iostream>
using namespace std;

int findMax(int a, int b){
	if(a < b){
		return b;
	}
	else{
		return a;
	}
}

int main(){
	int i, j, size, max;
	
	cout << "Enter the total number of elements\n";
	cin >> size;

	int A[size], dp[size];

	cout << "Enter the elements of array\n";

	for(i = 0; i < size; i++){
		cin >> A[i];
	}

	// initialising the dp[]
	for(i = 0; i < size; i++){
		dp[i] = 1;
	}

	i = j = max = 0;

	// dp algorithm
	while(i < size){
		if(A[j] < A[i]){
			dp[i] = findMax(dp[i], 1+dp[j]);
			j++;
		}
		else if(j+1 < i){
			j++;
		}
		else{
			i++;
			j = 0;
		}
	}

	for(i = 0; i < size; i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}

	cout << "Length of longest increasing subsequence is: " << max << "\n";

	cout << "dp[]: ";
	for(i = 0; i < size; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";

	return 0;
} 