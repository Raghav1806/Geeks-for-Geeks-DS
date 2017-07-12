// printing longest common subsequence
#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b){
	return (a > b)? a:b;
}

// function to return length og LCS
int lcs(char *X, char *Y, int m, int n){
	int L[m+1][n+1];
	int i, j;

	// bottom up fashion is implimented
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++){
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;

			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	// L[m][n] contains the answer
	return L[m][n];
}

int main(){
	char X[50], Y[50];
	cout<<"Enter 2 strings\n";
	cin>>X>>Y;

	int m = strlen(X);
	int n = strlen(Y);

	cout<<"Length of longest common subsequence is "<<lcs(X, Y, m, n)<<"\n";

return 0;
}
