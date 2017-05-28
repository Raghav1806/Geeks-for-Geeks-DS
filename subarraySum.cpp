// Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.

#include<iostream>

using namespace std;

int main(){
int size,sum,i,sum1,check,low,high;
low = high = sum = sum1 = check = 0;

cout<<"Enter size of array:\n";
cin>>size;
int A[size];
cout<<"Enter elements of array\n";

for(i=0;i<size;i++)
cin>>A[i];

cout<<"Enter the desired sum\n";
cin>>sum;

sum1 = A[low];

while(low <= high && high < size){
	if(sum1 == sum){
		check = 1;
		break;
	}
	if(sum1 > sum){
		sum1 = sum1 - A[low];
		low++;
	}
	if(sum1 < sum){
		sum1 = sum1 + A[high+1];
		high++;
	}
}

if(check == 1)
cout<<"Subarray found!\n";
else
cout<<"Subarray not found\n";
return 0;
}
