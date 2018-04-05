// Given two strings and operations edit, delete and add, how many minimum operations would it take to convert one string into another.
#include <iostream>
#include <cstring>
using namespace std;

int findMin(int a, int b, int c){
	if(a <= b && a <= c){
		return a;
	}
	else if(b <= a && b <= c){
		return b;
	}
	else{
		return c;
	}
}

int main(){
	int i, j, len1, len2;
	string A, B;

	cout << "Enter the two strings\n";
	cin >> A >> B;

	len1 = A.length();
	len2 = B.length();

	int dp[len1+1][len2+1];

	// initialising the dp[][]
	for(i = 0; i < len1+1; i++){
		dp[i][0] = i;
	}
	for(j = 0; j < len2+1; j++){
		dp[0][j] = j;
	}

	// applying the dp agorithm
	for(i = 1; i < len1+1; i++){
		for(j = 1; j < len2+1; j++){
			if(A[i-1] == B[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1+findMin(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
			}
		}
	}

	cout << "Total number of operations are: " << dp[len1][len2] << "\n";
	cout << "The resultant dp[][] is:\n";

	for(i = 0; i < len1+1; i++){
		for(j = 0; j < len2+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}