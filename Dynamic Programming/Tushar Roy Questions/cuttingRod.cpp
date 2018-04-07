// given a rod of a particular length, and prices at which different length of this rod can be sold, find the maximum profit you can generate.
#include <iostream>
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
	int i, j, lengthOfRod, diffLengthAvailable;

	cout << "Enter the total length of rod\n";
	cin >> lengthOfRod;

	cout << "Enter the number of types of length available\n";
	cin >> diffLengthAvailable;

	int dp[diffLengthAvailable][lengthOfRod+1], value[diffLengthAvailable], length[diffLengthAvailable];

	cout << "Enter (in ascending order) the length of each individual length available\n";
	for(i = 0; i < diffLengthAvailable; i++){
		cin >> length[i];
	}

	cout << "Enter the values of respective individual length\n";
	for(i = 0; i < diffLengthAvailable; i++){
		cin >> value[i];
	}

	// initialise the dp[][]
	for(i = 0; i < diffLengthAvailable; i++){
		dp[i][0] = 0;
	}
	for(i = 1; i < lengthOfRod+1; i++){
		dp[0][i] = (i*value[0])/length[0];
	}

	// dp algorithm
	for(i = 1; i < diffLengthAvailable; i++){
		for(j = 1; j < lengthOfRod+1; j++){
			if(length[i] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = findMax(dp[i-1][j], value[i]+dp[i][j-length[i]]);
			}
		}
	}

	cout << "Max possible price is: " << dp[diffLengthAvailable-1][lengthOfRod] << "\n";
	cout << "Value of dp[][] is:\n";

	for(i = 0; i < diffLengthAvailable; i++){
		for(j = 0; j < lengthOfRod+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}