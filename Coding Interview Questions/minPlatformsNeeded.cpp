/*
Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

Input:

First line will contain a number T, the number of test cases.
Each test case will contain a number N, the number of trains.
Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
NOTE: Time intervals are in 24 hour format(hhmm),preceding zeros are insignificant.
Consider the example for better understanding of input.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, i, j, numberOfPlatforms, ans;
	cin>>T;
	while(T--){
		numberOfPlatforms = 1;
		ans = 1;
		cin>>N;
		int arrival[N], departure[N];
		for(i=0; i<N; i++)
			cin>>arrival[i];
		for(i=0; i<N; i++)
			cin>>departure[i];

		sort(arrival, arrival+N);
		sort(departure, departure+N);

		i = 1;
		j = 0;

		// process similar to merge sort
		while(i<N && j<N){
			// arrival of a train is before departure
			if(arrival[i] < departure[j]){
				numberOfPlatforms++;
				i++;
				if(numberOfPlatforms > ans)
					ans = numberOfPlatforms;
			}

			else{
				numberOfPlatforms--;
				j++;
			}
		}

		cout<<ans<<"\n";
	}
return 0;
}



