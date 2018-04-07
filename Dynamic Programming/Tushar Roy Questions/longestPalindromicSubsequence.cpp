// given a string, find its longest palindromic subsequence
#include <iostream>
#include <cstring>
using namespace std;

int findMax(int a, int b){
	if(a >= b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int len, i, j, substringLength;
	string A;

	cout << "Enter the string\n";
	cin >> A;

	len = A.length();

	int dp[len][len];

	// initialising the dp[][]
	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			if(i == j){
				// substringLength = 1
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	// dp algorithm
	for(substringLength = 2; substringLength <= len; substringLength++){
		for(i = 0; i < len-substringLength + 1; i++){
			j = i + substringLength - 1;
			if(A[i] == A[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}
			else{
				dp[i][j] = findMax(dp[i][j-1], dp[i+1][j]);
			}
		}
	}

	cout << "Length of longest palindromic subsequence is: " << dp[0][len-1] << "\n";
	cout << "The resultant dp[][] is:\n";

	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}