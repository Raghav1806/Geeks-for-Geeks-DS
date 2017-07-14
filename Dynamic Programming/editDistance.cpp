// find minimum number of operations to convert str1 to str2

#include <iostream>
#include <cstring>
using namespace std;

int min(int x, int y, int z){
	if(x <= y && x <= z)
		return x;
	else if(y <= x && y <= z)
		return y;
	else
		return z;
}

int editDist(string str1, string str2, int m, int n){
	// table to store results of subproblems
	int dp[m+1][n+1];

	// fill dp[][] in bottom up manner
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			// if first string is empty, only option is to insert all characters of second string
			if(i == 0)
				dp[i][j] = j;

			// if second string is empty, only option is to remove all characters of second string
			else if(j == 0)
				dp[i][j] = i;

			// if last characters are same, ignore last characters and recur for remaining string
			else if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];

			// if last characters are different, consider all possibilties and find minimum
			else
				dp[i][j] = 1 + min(dp[i][j-1],		// insert
						   dp[i-1][j],		// remove
						   dp[i-1][j-1]);	// replace
		}
	}

return dp[m][n];
}

int main(){

    	string str1 = "sunday";
    	string str2 = "saturday";
 
    	cout << editDist(str1, str2, str1.length(), str2.length());
 
return 0;
}

