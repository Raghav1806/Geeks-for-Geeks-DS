/*
Given an array A your task is to tell at which position the equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.
*/

#include <iostream>
using namespace std;

int main() {
	int T, N, i, sum, leftSum, ans;
	cin>>T;
	while(T--){
		sum = leftSum = 0;
		cin>>N;
		int A[N];
		for(i=0; i<N; i++){
			cin>>A[i];
			sum += A[i];
		}	

		for(i=0; i<N; i++){
			sum -= A[i];
			if(sum == leftSum){
				ans = i+1;
				break;
			}
			leftSum += A[i];
		}

		if(i == N)
			cout<<i<<"\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}
