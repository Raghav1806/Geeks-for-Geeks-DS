// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

// deque (double-ended queue is used in this case)

#include<iostream>
#include<deque>
using namespace std;

void printKMax(int A[], int size, int k){
	std::deque<int> Q(k);
	int i;
	for(i=0; i<k; i++){
		while((!Q.empty()) && A[i] >= A[Q.back()])
			Q.pop_back();

		Q.push_back(i);
	}

	for(i=k; i<size; i++){
		cout<<A[Q.front()]<<" ";
		while(!(Q.empty()) && Q.front() <= i-k)
			Q.pop_front();

		while((!Q.empty()) && A[i] >= A[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	cout<<A[Q.front()]<<"\n";
}

int main(){
int size, i, k;

cout<<"Enter the size of array\n";
cin>>size;
int A[size];

cout<<"Enter the elements of array\n";
	for(i=0; i<size; i++)
		cin>>A[i];

cout<<"Enter the value of k\n";
cin>>k;
	printKMax(A, size, k);
return 0;
}
