// program for memoized version of nth fibbonacci number

#include <iostream>
using namespace std;
#define NIL -1
#define MAX 100

int lookup[MAX];

// function to initialize NIL values in lookup table
void initialize(){
	int i;
	for(i=0; i<MAX; i++)
		lookup[i] = NIL;
}

// function for nth fibonacci number
int fib(int n){
	if(lookup[n] == NIL){
		if(n <= 1)
			lookup[n] = n;
		else
			lookup[n] = fib(n-1) + fib(n-2);
	}

	return lookup[n];
}

int main(){
	int n = 40;
	initialize();
	cout<<"fibonacci number is "<<fib(n)<<"\n";
	return 0;
}
