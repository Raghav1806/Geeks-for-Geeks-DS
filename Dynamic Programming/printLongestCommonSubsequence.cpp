// program for printing longest common subsequence
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void lcs(char *X, char *Y, int m, int n){
	int L[m+1][n+1];

	// building up table in bottom-up manner
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	// this code is used to print LCS
	int index = L[m][n];

	// create a character array to store the lcs string
	char lcs[index+1];
	lcs[index] = '\0';

	// one by one store characters in lcs[]
	int i = m;
	int j = n;

	while(i > 0 && j > 0){
		// if current character in X[] and Y[] are same, then current character is part of LCS
		if(X[i-1] == Y[j-1]){
			lcs[index-1] = X[i-1];
			i--;
			j--;
			index--;
		}

		// if not same, then find the larger of two and go in the direction of larger value
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

// print the LCS
cout<<"LCS of "<<X<<"& "<<Y<<" is "<<lcs<<"\n";
}

int main(){
	char X[50], Y[50];
	cout<<"Enter 2 strings\n";
	cin>>X>>Y;
	int m = strlen(X);
	int n = strlen(Y);
	lcs(X, Y, m, n);
return 0;
}
