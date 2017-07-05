/*
There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

If we observe the above problem closely, we can notice that the lengths of the ropes which are picked first are included more than once in total cost. Therefore, the idea is to connect smallest two ropes first and recur for remaining ropes.
*/

#include <iostream>
#include <queue>
using namespace std;

int minCost(int arr[], int n){
	
	// create a priority queue, by default 'less' is used which is for decreasing order and 'greater' is used for increasing order
	priority_queue< int, vector<int>, greater<int> > pq(arr, arr+n);

	// initialise result
	int res = 0;

	// while size of priority queue is more than 1
	while (pq.size() > 1){
		// extract shortest two ropes from pq
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		// connect the ropes, update result and insert the new rope to pq
		res += first + second;
		pq.push(first + second);
	}
return res;
}

int main(){
	int size, i;
	cout<<"Enter the size of array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of arrray\n";
	for(i=0; i<size; i++)
		cin>>A[i];
	cout<<"Total cost for connecting ropes is\n"<<minCost(A, size);

return 0;
}
