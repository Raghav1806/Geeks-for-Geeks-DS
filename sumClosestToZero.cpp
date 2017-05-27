// An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.

#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 10000000

using namespace std;

int main(){

int size,i,min,start,end,num,num1,num2;
cout<<"Enter the size of array\n";
cin>>size;

int A[size];
cout<<"Enter the elements of array\n";

	for(i=0;i<size;i++)
		cin>>A[i];

sort(A,A+size);

start = 0;
end = size-1;
min = MAX;

	while(start < end){
		num = A[start]+A[end];

			if(min > abs(num)){
				min = num;
				num1 = A[start];
				num2 = A[end];
			}

			if(num <= 0)
				start++;
			if(num > 0)
				end--;
	}

cout<<"Min Absolute Diff: "<<min<<"\n";
cout<<"Num 1: "<<num1<<"\n";
cout<<"Num 2: "<<num2<<"\n";

return 0;
}
