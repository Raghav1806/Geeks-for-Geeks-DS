#include<iostream>

using namespace std;

int main(){
int size,i,leftTop,rightTop,temp;
cout<<"Enter size of array\n";
cin>>size;

leftTop = 0;
rightTop = size-1;

cout<<"Enter elements of Array\n";
int A[size];

for(i=0;i<size;i++)
cin>>A[i];

while(leftTop < rightTop){
while(A[leftTop]%2 == 0 && leftTop < rightTop)
leftTop++;
while(A[rightTop]%2 == 1 && leftTop < rightTop)
rightTop--;
if(leftTop < rightTop){
temp = A[leftTop];
A[leftTop] = A[rightTop];
A[rightTop] = temp;
}
}

for(i=0;i<size;i++)
cout<<A[i]<<" ";

cout<<"\n";

return 0;
}
