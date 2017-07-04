// program to demonstrate comon binary heap operations
#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

class minHeap{
	int *harr;	// pointer to array of elements in heap
	int capacity;	// maximum possible size of min heap
	int heapSize;	// current number of elements in min heap

	public:
		// constructor
		minHeap(int capacity);

		// to heapify a subtree with root at given index
		void minHeapify(int);

		int parent(int i){
			return (i-1)/2;
		}

		// to get index of left child of node at index i
		int left(int i){
			return (2*i + 1);
		}

		// to get index of right child of node at index i
		int right(int i){
			return (2*i + 2);
		}

		// to extract root which is the minimum element
		int extractMin();

		// decreases key value of key at index i to newval
		void decreaseKey(int i, int newVal);

		// returns minimum key from min heap
		int getMin(){
			return harr[0];
		}

		// deletes a key stored at index i
		void deleteKey(int i);

		// insert a new key 'k'
		void insertKey(int k);	
};

// constructor: builds a heap of given capacity
minHeap::minHeap(int cap){
	heapSize = 0;
	capacity = cap;
	harr = new int[cap];
}

// insert a new key 'k'
void minHeap::insertKey(int k){
	if(heapSize == capacity){
		cout<<"Overflow: key could not be inserted\n";
		return;
	}

	// first insert the key at the end
	heapSize++;
	int i = heapSize-1;
	harr[i] = k;

	// fix the min heap property if it is violated
	while(i != 0 && harr[parent(i)] > harr[i]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// decrease the value of key at index 'i' to newVal. It is assumed newVal is smaller than harr[i]
void minHeap::decreaseKey(int i, int newVal){
	harr[i] = newVal;
	while(i != 0 && harr[parent(i)] > harr[i]){
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// method to remove minimum element (or root) from min heap
int minHeap::extractMin(){
	if(heapSize <= 0)
		return INT_MAX;
	if(heapSize == 1){
		heapSize--;
		return harr[0];
	}

	// store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heapSize-1];
	heapSize--;
	minHeapify(0);

return root;
}

// this function deletes key at index i
void minHeap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	extractMin();
}

// a recursive method to heapify a subtree with root at given index. This method assumes that the subtrees are already heapified.
void minHeap::minHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heapSize && harr[l] < harr[smallest])
		smallest = l;
	if(r < heapSize && harr[r] < harr[smallest])
		smallest = r;
	if(smallest != i){
		swap(&harr[i], &harr[smallest]);
		minHeapify(smallest);
	}
}

int main(){
	
	minHeap h(11);
    	h.insertKey(3);
    	h.insertKey(2);
    	h.deleteKey(1);
    	h.insertKey(15);
    	h.insertKey(5);
    	h.insertKey(4);
    	h.insertKey(45);
    	cout << h.extractMin() << " ";
    	cout << h.getMin() << " ";
    	h.decreaseKey(2, 1);
    	cout << h.getMin();

return 0;
}
