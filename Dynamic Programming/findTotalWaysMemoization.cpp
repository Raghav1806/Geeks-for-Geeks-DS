/*
Using memoization to solve this problem:

Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is : 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1
*/

#include <iostream>
using namespace std;
#define MAX 100
#define NIL -1

int dp[MAX];

void initialise(){
	for(int i = 0; i < MAX; i++)
		dp[i] = NIL;
}

int solve(int n){
	// base case
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;

	// checking if already calculated
	if(dp[n] != NIL)
		return dp[n];
	// storing the result and returning
	return dp[n] = solve(n-1) + solve(n-3) + solve(n-5); 
}

int main(){
	int num;
	cout<<"Enter the number\n";
	cin>>num;
	initialise();
	cout<<"The total number of possibilities are: "<<solve(num)<<"\n";

return 0;
}
