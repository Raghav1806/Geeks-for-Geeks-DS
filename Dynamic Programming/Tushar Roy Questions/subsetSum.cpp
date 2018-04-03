// Given a set of non negative numbers and a total, find if there exists a subset 
// in this set whose sum is same as total
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int sum, size, i, j;

	cout << "Enter the sum to be checked\n";
	cin >> sum;

	cout << "Enter the total number of elements in set\n";
	cin >> size;

	int elements[size];
	bool dp[size][sum+1];

	cout << "Enter the elements in the given set\n";
	
	for(i = 0; i < size; i++){
		cin >> elements[i];
	}

	sort(elements, elements+size);

	// intitialising the dp
	for(i = 0; i < size; i++){
		dp[i][0] = true; 
	}

	for(j = 1; j < sum+1; j++){
		if(j != elements[0]){
			dp[0][j] = false;
		}
		else{
			dp[0][j] = true;
		}
	}

	// applying dp algorithm
	for(i = 1; i < size; i++){
		for(j = 0; j < sum+1; j++){
			if(j < elements[i]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-elements[i]];
			}
		}
	}

	if(dp[size-1][sum] == true){
		cout << "Given sum is achievable!\n";
	}
	else{
		cout << "Given sum is not achievable\n";
	}

	cout << "The resultant dp 2D matrix is:\n";
	for(i = 0; i < size; i++){
		for(j = 0; j < sum+1; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}