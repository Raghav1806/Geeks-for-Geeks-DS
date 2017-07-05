// shell sort program

#include <iostream>
using namespace std;

int shellSort(int A[], int n){
	// start with a big gap, then reduce the gap
	for(int gap = n/2; gap > 0; gap /= 2){
		// do a gapped insertion sort for this gap size
		for(int i = gap; i < n; i++){
			int temp = A[i];
			int j;	
			for(j = i; j >= gap & A[j-gap] > temp; j -= gap)
				A[j] = A[j-gap];

			A[j] = temp;
		}
	}
return 0;
}

void printArray(int arr[], int n){

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main(){

    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Array before sorting: \n";
    printArray(arr, n);
 
    shellSort(arr, n);
 
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
 
    return 0;
}
