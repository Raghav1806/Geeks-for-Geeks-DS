// Given set of coins of unlimited quantity and a total, how many coins would it take to form this total
#include <iostream>
using namespace std;

#define INF 100000

int main(){
	int i, j, numberOfCoins, desiredSum;

	cout << "Enter the desired sum\n";
	cin >> desiredSum;

	cout << "Enter the total types of coins available\n";
	cin >> numberOfCoins;

	int coins[numberOfCoins];
	
	cout << "Enter the denomination of each coin\n";
	for(i = 0; i < numberOfCoins; i++){
		cin >> coins[i];
	}

	// numberOfCoinsNeeded[] stores the total number of coins required for a particular sum
	// typesOfCoinsUsed is used to determine diff types of coins used to achieve a particualar sum
	int numberOfCoinsNeeded[desiredSum+1], typesOfCoinsUsed[desiredSum+1];

	// initialising the arrays
	numberOfCoinsNeeded[0] = 0;
	for(i = 1; i < desiredSum+1; i++){
		numberOfCoinsNeeded[i] = INF;
	}
	for(i = 0; i < desiredSum+1; i++){
		typesOfCoinsUsed[i] = -1;
	}

	// dp algorithm
	for(i = 0; i < desiredSum+1; i++){
		for(j = 0; j < numberOfCoins; j++){
			if(coins[j] <= i){
				if(1+numberOfCoinsNeeded[i-coins[j]] < numberOfCoinsNeeded[i]){
					typesOfCoinsUsed[i] = j;
					numberOfCoinsNeeded[i] = 1+numberOfCoinsNeeded[i-coins[j]];
				}
			}
		}
	}

	if(numberOfCoinsNeeded[desiredSum] != INF){
		cout << "Desired sum is achievable with " << numberOfCoinsNeeded[desiredSum] << " coins\n";
		cout << "The coins used are:\n";
		while(desiredSum != 0){
			cout << coins[typesOfCoinsUsed[desiredSum]] << " ";
			desiredSum -= coins[typesOfCoinsUsed[desiredSum]];
		}
		cout << "\n";
	}

	return 0;
}