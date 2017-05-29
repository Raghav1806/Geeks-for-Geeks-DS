// finding longest subsequence in an entered array
#include<iostream>
using namespace std;

int findLIS(int a[],int n){
int b[n],i,j;
int max = 0;

// Initialize LIS values for all indexes
for(i=0;i<n;i++)
b[i] = 1;

// computing optimized LIS values in bottom up manner
for(i=0;i<n;i++)
	for(j=0;j<i;j++)
		if(a[i]>a[j] && b[i]<b[j]+1)
			b[i]=b[j]+1;

// pick maximum of all LIS values
for(i=0;i<n;i++)
	if(max<b[i])
		max=b[i];

return max;
}

int main(){
int n,i,ans;
cout<<"Enter size of array\n";
cin>>n;
int a[n];
cout<<"Enter elements of array\n";

	for(i=0;i<n;i++)
		cin>>a[i];

ans = findLIS(a,n);
cout<<ans<<"\n";
}
