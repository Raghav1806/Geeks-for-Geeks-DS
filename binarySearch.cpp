// Program demonstrating binary search in a sorted array (ascending order)
#include<iostream>

using namespace std;

int binarySearch(int A[],int i,int start,int end){
	if(start > end)
		return -1;
int mid = (start+end)/2;
int ans;
	if(A[mid] == i){
		ans = mid;
		return ans;
	}
	if(A[mid] > i){
		end = mid-1;
		binarySearch(A,i,start,end);
	}
	if(A[mid] < i){
		start = mid+1;
		binarySearch(A,i,start,end);
	}
}

int main(){
int size,i,ans;
cout<<"Enter size of sorted array\n";
cin>>size;
int A[size];
cout<<"Enter the elements in ascending order\n";

	for(i=0;i<size;i++)
	cin>>A[i];

cout<<"Enter the element to be searched for\n";
cin>>i;

ans = binarySearch(A,i,0,size-1);

if(ans != -1)
cout<<"Element found!\n";

else
cout<<"Element not found!\n";

return 0;
}
