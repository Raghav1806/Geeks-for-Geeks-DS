// Using BitWise XOR to find the element ocurring odd number of times

#include<iostream>

using namespace std;

int main(){

int size,i,ans;
ans = 0;

cout<<"Enter size of array\n";
cin>>size;
int A[size];
cout<<"Enter the elements of array\n";

for(i=0;i<size;i++)
cin>>A[i];

for(i=0;i<size;i++)
ans = ans^A[i];

cout<<"The element occurring odd number of times is "<<ans<<"\n";
return 0;
}  
