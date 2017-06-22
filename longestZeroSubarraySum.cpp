// Program to find length of largest subarray with 0 sum

/*
Algorithm:
The idea is to iterate through the array and for every element arr[i], calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero sum array.
*/

#include <iostream>
#include <map>
using namespace std;

int maxLen(int A[], int n){
	// Map to store previous sums
	map<int, int> presum;

	int sum = 0;
	int max_len = 0;

	for(int i = 0; i < n; i++){
		sum += A[i];
		if(A[i] == 0 && max_len == 0)
			max_len = 1;
		if(sum == 0)
			max_len = i+1;

		// Look for this sum in hash table
		if(presum.find(sum) != presum.end()){
			max_len = max(max_len, i-presum[sum]);
		}
		else{
			// insert this sum with index in hash table
			presum[sum] = i;
		}
	}
return max_len;
}

int main(){

int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
int n = sizeof(arr)/sizeof(arr[0]);
 
cout<<"Length of the longest 0 sum subarray is "<< maxLen(arr, n)<<"\n";
return 0;
}

