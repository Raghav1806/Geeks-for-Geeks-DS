/* Bucket Sort algorithm

1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort(float A[], int size){
vector<float> B[size];	// n empty buckets
int bi,i,j,index;
index = 0;

	// Put array elements in different buckets
	for(i=0;i<size;i++){
		bi = size*A[i];
		B[bi].push_back(A[i]);
	}
	
	// Sort individual buckets
	for(i=0;i<size;i++)
		sort(B[i].begin(), B[i].end());

	// Concatenate all buckets into A[]
	for(i=0;i<size;i++)
		for(j=0;j<B[i].size();j++)
			A[index++] = B[i][j];	
}

int main(){
int size,i;
cout<<"Enter the size of float array\n";
cin>>size;
float A[size];
cout<<"Enter the elements of array (0-1)\n";
	for(i=0;i<size;i++)
		cin>>A[i];
bucketSort(A,size);
cout<<"Sorted array is\n";
	for(i=0;i<size;i++)
		cout<<A[i]<<" ";
cout<<"\n";
return 0;
}
