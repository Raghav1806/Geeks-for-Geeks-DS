/*
Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.
*/

#include <bits/stdc++.h>
using namespace std;

int subArraySum(int A[], int N, int S){
	int currSum, start, i;
	start = 0;
	currSum = A[0];

	// add elements one by one to currSum if the curr_sum is greater than sum, then remove the starting element
	for(i=1; i<=N; i++){
		// if currSum exceeds the sum, then remove the starting element
		while(currSum > S && start < i-1){
			currSum = currSum - A[start];
			start++;
		}

		// if currSum == sum, return true
		if(currSum == S){
			cout<<start+1<<" "<<i<<"\n";
			return 1;
		}
		
		// add this element to currSum
		if(i < N)
			currSum = currSum + A[i];
	}

	// if we reach here, there is no subarray
		cout<<"-1"<<"\n";
		return 0;
}

int main(){
	int T, N, S, i;
	cin>>T;
	while(T--){
		cin>>N>>S;
		int A[N];
		for(i=0; i<N; i++)
			cin>>A[i];
		i = subArraySum(A, N, S);
	}
return 0;
}

