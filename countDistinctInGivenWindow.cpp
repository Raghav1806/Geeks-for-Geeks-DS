// count distinct elements in every window of size k

#include <iostream>
using namespace std;

int findDistinct(int Hash[], int size){
	int i, count;
	count = 0;
	for(i = 0; i < size; i++)
		if(Hash[i] != 0)
			count++;
return count;	
}

int main(){
	int size, i, k, distinct;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size], Hash[size];
	cout<<"Enter the elements of array\n";
	for(i = 0; i < size; i++)
		cin>>A[i];
	for(i = 0; i < size; i++)
		Hash[i] = 0;
	cout<<"Enter the window size\n";
	cin>>k;

	for(i = 0; i < k; i++){
		Hash[A[i]]++;
	}

	distinct = findDistinct(Hash, size);
	cout<<distinct<<"\n";

	for(i = 1; i+k <= size; i++){
		Hash[A[i-1]]--;
		if(Hash[A[i-1]] == 0)
			distinct--;
		Hash[A[i+k-1]]++;
		if(Hash[A[i+k-1]] == 1)
			distinct++;
		cout<<distinct<<"\n";
	}
return 0;
}
