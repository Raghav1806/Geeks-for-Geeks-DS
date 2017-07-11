/*
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is : 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1

-> state(n) = state(n-1) + state(n-3) + state(n-5)

*/

#include <iostream>
using namespace std;

int state(int n){
	// base case
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	return state(n-1) + state(n-3) + state(n-5);
}

int main(){
	int n;
	cout<<"Enter the number\n";
	cin>>n;
	cout<<"The total number of possibilities are: "<<state(n)<<"\n";

return 0;
}
