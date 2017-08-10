/*
Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, i, max_i, max_so_far;
	cin>>T;

	while(T--){
		cin>>N;
		int A[N];
		for(i=0; i<N; i++)
			cin>>A[i];
		max_i = A[0];
		max_so_far = A[0];

		for(i=1; i<N; i++){
			max_i = max(A[i], max_i + A[i]);
			max_so_far = max(max_i, max_so_far);
		}

		cout<<max_so_far<<"\n";
	}
return 0;
}
