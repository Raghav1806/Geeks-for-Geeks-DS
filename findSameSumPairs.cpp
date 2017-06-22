// Find four elements a, b, c and d in an array such that a+b = c+d
/* 
Pseudo Code:
Loop i = 0 to n-1 :
    Loop j = i + 1 to n-1 :
        calculate sum
        If in hash table any index already exist
            Then print (i, j) and previous pair 
            from hash table  
        Else update hash table
    EndLoop;
EndLoop;
*/

#include <iostream>
#include <map>
using namespace std;

bool findPairs(int A[], int n){
	// An empty hash to store mapping from sum to pair indexes
	map<int, pair<int, int> > Hash;
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
	// If sum of current pair is not in hash, then store it and continue to next pair
			int sum = A[i] + A[j];
			if(Hash.find(sum) == Hash.end())
				Hash[sum] = make_pair(i, j);
			else{
				pair<int, int> pp = Hash[sum];
				cout<<"("<<A[pp.first]<<","<<A[pp.second]<<") and ("<<A[i]<<","<<A[j]<<")\n";
				return true;
			} 
		}
	}
cout<<"No pairs found\n";
return false;
}

int main(){
	int i, size;
	cout<<"Enter size of Array\n";
	cin>>size;
	int A[size];
	cout<<"Enter the elements of Array\n";
	for(int i = 0; i < size; i++)
		cin>>A[i];
	findPairs(A, size);
return 0;
}
