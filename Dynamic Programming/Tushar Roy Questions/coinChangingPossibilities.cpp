// given infinite coins of certain denominations and a total, how many ways these coins can be combined to get the total?
#include <iostream>
using namespace std;

int main(){
	int i, j, typesOfCoins, total;

	cout << "Enter the desired sum of coins\n";
	cin >> total;

	cout << "Enter the available types of coins\n";
	cin >> typesOfCoins;

	int coinDenomination[typesOfCoins];

	cout << "Enter all the available coin denominations\n";

	for(i = 0; i < typesOfCoins; i++){
		cin >> coinDenomination[i];
	}

	int dp[typesOfCoins][total+1];

	// initialising the dp[][]
	for(i = 0; i < typesOfCoins; i++){
		dp[i][0] = 1;
	}
	for(i = 0; i < total+1; i++){
		dp[0][i] = 1;
	}

	// dp algorithm
	for(i = 1; i < typesOfCoins; i++){
		for(j = 1; j < total+1; j++){
			if(coinDenomination[i] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i][j-coinDenomination[i]];
			}
		}
	}

	cout << "The total number of ways to achieve the desired sum is: " << dp[typesOfCoins-1][total] << "\n";
	cout << "The dp[][] matrix is:\n";

	for(i = 0; i < typesOfCoins; i++){
		for(j = 0; j < total+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}