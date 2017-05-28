// Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
int size1,size2,i,j;
cout<<"Enter the size of two arrays\n";
cin>>size1>>size2;
int A[size1],B[size2];

cout<<"Enter elements of array 1:\n";
for(i=0;i<size1;i++)
cin>>A[i];

cout<<"Enter elements of array 2:\n";
for(i=0;i<size2;i++)
cin>>B[i];

sort(A,A+size1);
sort(B,B+size2);

i = j = 0;

while(i < size1 && j < size2){
	if(A[i] < B[j])
	i++;
	if(B[j] < A[i])
	j++;
	if(A[i] == B[j]){
		i++;
		j++;
	}
}

if(j == size2)
cout<<"Yes\n";

else
cout<<"No\n";

return 0;
}
