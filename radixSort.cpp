// Radix Sort Algorithm

#include<iostream>

using namespace std;

int getMax(int A[], int size)
{
    int max = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

void countSort(int A[], int size, int exp){
int output[size], count[10],i;
	for(i=0;i<10;i++)
		count[i] = 0;
	for(i=0;i<size;i++)
		count[(A[i]/exp)%10]++;

// change count[i] so that count[i] now contains actual position of this digit in output[]
	for(i=1;i<10;i++)
		count[i] += count[i-1];

// build the output array
	for(i=size-1;i>=0;i--){
		output[count[(A[i]/exp)%10]-1] = A[i];
		count[(A[i]/exp)%10]--;
	}
// copy the output array to A[], so that A[] is sorted
	for(i=0;i<size;i++)
		A[i] = output[i];
}

void radixSort(int A[],int size){
int m = getMax(A,size);
	for(int exp=1;m/exp>0;exp *= 10)
		countSort(A,size,exp);	
}

int main(){
int size,i;
cout<<"Enter the size of array to be sorted\n";
cin>>size;
int A[i];
cout<<"Enter the elements of array\n";
	for(i=0;i<size;i++)
		cin>>A[i];
radixSort(A,size);
cout<<"The sorted array is\n";
	for(i=0;i<size;i++)
		cout<<A[i]<<" ";
cout<<"\n";
return 0;
}
