/* 
Bucket Sort algorithm:

bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(float A[], int size){
	// create empty buckets
	vector<float> b[size];

	// put array elements in different buckets
	for(int i = 0; i < size; i++){
		int bi = size*A[i];	// index in bucket
		b[bi].push_back(A[i]);
	}

	// sort individual buckets
	for(int i = 0; i < size; i++)
		sort(b[i].begin(), b[i].end());

	// concatenate all buckets into A[]
	int index = 0;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < b[i].size(); j++)
			A[index++] = b[i][j];
}

int main(){
	int size, i;
	cout<<"Enter the size of array\n";
	cin>>size;
	float A[size];
	cout<<"Enter the elements of array\n";
	for(i = 0; i < size; i++)	
		cin>>A[i];

	bucketSort(A, size);

	cout<<"The sorted array is\n";
	for(i = 0; i < size; i++)
		cout<<A[i]<<" ";
cout<<"\n";

return 0;
}
