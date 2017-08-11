/*
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. The rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, i, index, max;
	cin>>T;
	while(T--){
		max = index = 0;
		cin>>N;
		int A[N];
		for(i=0; i<N; i++)
			cin>>A[i];

		// traverse the array from right side 
		for(i=N-1; i>=0; i--){
			if(A[i] >= max){
				cout<<A[i]<<" ";
				max = A[i];
			}
		}
		cout<<"\n";
	}
return 0;
}
