// given certain jobs (in ascending order of end-time) and amount you make on finishing the job, find the maximum value you can make by scheduling jobs in non-overlapping way.
#include <iostream>
using namespace std;

int findMax(int dp[], int size){
	int i, max;
	max = 0;

	for(i = 0; i < size; i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}

	return max;
}

int main(){
	int i, j, numberOfJobs;

	cout << "Enter the total number of jobs to be completed\n";
	cin >> numberOfJobs;

	int startTime[numberOfJobs], endTime[numberOfJobs], amount[numberOfJobs], dp[numberOfJobs];

	cout << "Enter the start-time and end-time of each job, respectively\n";

	for(i = 0; i < numberOfJobs; i++){
		cin >> startTime[i] >> endTime[i];
	} 

	cout << "Enter the amount you receive for completing each job\n";

	for(i = 0; i < numberOfJobs; i++){
		cin >> amount[i];
		dp[i] = amount[i];
	}

	// dp algorithm
	for(i = 1; i < numberOfJobs; i++){
		for(j = 0; j < i; j++){
			if(dp[i] < amount[i] + dp[j] && startTime[i] >= endTime[j]){
				dp[i] = amount[i] + dp[j];
			}
		}
	}

	cout << "Max amount that could be made is: " << findMax(dp, numberOfJobs) << "\n";
	cout << "dp[] is:\n";

	for(i = 0; i < numberOfJobs; i++){
		cout << dp[i] << " ";
	}
	cout << "\n";

	return 0;
}