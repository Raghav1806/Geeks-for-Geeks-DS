/*
Given a bag which can only take certain weight W. 
Given list of unique items with their weights and price, 
how do you fill this bag to maximise net value of items in the bag.
*/

#include <iostream>
using namespace std;

int main(){
	int maxWeight, numberOfItems, i, j;

	cout << "Enter the maximum capacity of knapsack\n";
	cin >> maxWeight;
	
	cout << "Enter the number of unique items available\n";
	cin >> numberOfItems;

	int dp[numberOfItems][maxWeight+1], weight[numberOfItems], value[numberOfItems];

	cout << "Enter the weight and value of an item\n";
	for(i = 0; i < numberOfItems; i++){
		cin >> weight[i];
		cin >> value[i];
	}

	// initializing the dp[][]
	for(i = 0; i < numberOfItems; i++){
		dp[i][0] = 0;
	}

	for(j = 0; j <= maxWeight; j++){
		if(j < weight[0]){
			dp[0][j] = 0;
		}
		else{
			dp[0][j] = value[0];
		}
	}

	for(i = 1; i < numberOfItems; i++){
		for(j = 1; j <= maxWeight; j++){
			if(j < weight[i]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
			}
		}
	}

	cout << "Max possible value is: " << dp[numberOfItems-1][maxWeight] << "\n";

	cout << "The resultant 2D dp table is:\n";
	for(i = 0; i < numberOfItems; i++){
		for(j = 0; j <= maxWeight; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}