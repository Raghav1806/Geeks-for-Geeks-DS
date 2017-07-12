#include <iostream>
using namespace std;

int min(int a, int b){
	return (a < b) ? a:b;
}

// returns value of binomial coefficient, C(n, k)
int binomialCoeff(int n, int k){
	int C[n+1][k+1];
	int i, j;

	// calculate the value of binomial coeficient in bottom up manner
	for(i=0; i<=n; i++){
		for(j=0; j <= min(i, k); j++){
			// base case
			if(j == 0 || j == i)	
				C[i][j] = 1;

			// calculate value using previously stored values
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	return C[n][k];
}

int main(){
	int n = 5;
	int k = 2;
	cout<<"Value of C(5, 2) is "<<binomialCoeff(5, 2)<<"\n";
	return 0;
}
