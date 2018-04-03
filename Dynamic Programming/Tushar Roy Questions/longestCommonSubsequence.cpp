// Given two strings, find longest common subsequence between them
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string A, B;
	int i, j, len1, len2;
	cout << "Enter the two strings\n";
	cin >> A >> B;

	len1 = A.length();
	len2 = B.length();
	
	int dp[len1+1][len2+1];

	// initialising the dp
	for(i = 0; i < len1+1; i++){
		dp[i][0] = 0;
	}

	for(j = 0; j < len2+1; j++){
		dp[0][j] = 0;
	}

	// applying dp algorithm
	for(i = 1; i < len1+1; i++){
		for(j = 1; j < len2+1; j++){
			if(A[i-1] == B[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout << "Length of longest common subsequence is: " << dp[len1][len2] << "\n";

	cout << "The resultant dp 2D matrix is:\n";
	for(i = 0; i < len1+1; i++){
		for(j = 0; j < len2+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}