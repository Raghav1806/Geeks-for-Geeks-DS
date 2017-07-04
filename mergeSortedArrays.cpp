// given k sorted arrays of size n each, merge the and print the sorted output

/* 
Algorithm:
1. Create an output array of size n*k.
2. Create a min heap of size k and insert 1st element in all the arrays into the heap
3. Repeat following steps n*k times.
     a) Get minimum element from heap (minimum is always at root) and store it in output array.
     b) Replace heap root with next element from the array from which the element is extracted. If the array doesn’t have any more elements, then replace root with infinite. After replacing the root, heapify the tree.
*/

#include <iostream>
#include <climits>
using namespace std;

#define n 4

// a min heap node
struct minHeapNode{
	int element;
	int i;	// index of array from which element is taken
	int j;	// index of next element to be picked from array
};

void swap(minHeapNode *x, minHeapNode *y){
	minHeapNode temp = *x;
	*x = *y;
	*y = temp;
}

class minHeap{
	minHeapNode *harr;	// pointer to array of elements in heap
	int heapSize;		// size of min heap

	public:
		// constructor: creates min heap of given size
		minHeap(minHeapNode a[], int size);

		// to get index of left child of node at index i
		int left(int i){
			return (2*i + 1);
		} 

		// to get index of right child of node at index i
		int right(int i){
			return (2*i + 2);
		}

		// to get the root
		minHeapNode getMin(){
			return harr[0];
		}

		// to replace root with new node x and heapify() new root
		void replaceMin(minheapNode x){
			harr[0] = x;
			minHeapify(0);
		}
};

int *mergeKArrays(int arr[][n], int k){
	int *output = new int[n*k];	// to store output array

	// create a min heap with k heap nodes. Every heap node has first element of an array
	minHeapNode *harr = new minHeapNode[k];
	
	for(int i = 0; i < k; i++){
		harr[i].element = arr[i][0];	// store the first element
		harr[i].i = i;			// index of array
		harr[i],j = 1;			// index of next element to be stored from array
	}

	minHeap hp(harr, k);	// create a heap

	// now one by one get the minimum element from min heap and replace it with next element of its array
	for(int count = 0; count < n*k; count++){
		// get the minimum element and store it in output
		minHeapNode root = hp.getMin();
		output[count] = root.element;

		// find the next element that will replace current root of heap. The next element belongs to same array as the current root.
		if(root.j < n){
			root.element = arr[root.i][root.j];
			root.j += 1;
		}
		// if root was the last element of its array
		else
			root.element = INT_MAX;

		// replace root with next element of array
		hp.replaceMin(root);
	}
return output;
}

// constructor: builds a heap from a given array of given size
minHeap::minHeap(minHeapNode A[], int size){
	heapSize = size;
	harr = A;
	int i = (heapSize-1)/2;
	while(i >= 0){
		minHeapify(i);
		i--;
	}
}

void minHeap::minHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heapSize && harr[l].element < harr[smallest].element)
		smallest = l;
	if(r < heapSize && harr[r].element < harr[smallest])
		smallest = r;
	if(smallest != i){
		swap(&harr[i], &harr[smallest]);
		minHeapify(smallest);
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}

int main(){

    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);
 
    int *output = mergeKArrays(arr, k);
 
    cout << "Merged array is " << endl;
    printArray(output, n*k);
 
    return 0;
}
