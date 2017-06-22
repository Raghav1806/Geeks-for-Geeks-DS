// Program to find number of employees under every employee
// {employee, manager}

/* 
ALgorithm:
1. Create a reverse map with Manager->DirectReportingEmployee 
    combination. Off-course employee will be multiple so Value 
    in Map is List of Strings.
        "C" --> "A", "B",
        "E" --> "D" 
        "F" --> "C", "E", "F"

 
2. Now use the given employee-manager map to iterate  and at 
   the same time use newly reverse map to find the count of 
   employees under manager.
   
   Let the map created in step 2 be 'mngrEmpMap' 
   Do following for every employee 'emp'.
     a) If 'emp' is not present in 'mngrEmpMap' 
          Count under 'emp' is 0 [Nobody reports to 'emp']
     b) If 'emp' is present in 'mngrEmpMap' 
          Use the list of direct reports from map 'mngrEmpMap'
          and recursively calculate number of total employees
          under 'emp'. 
*/

#include <iostream>
using namespace std;

int main(){
	int size;
	char employee, manager;
	cout<<"Enter the total number of employees\n";
	cin>>size;
	int relationship[size], i;
	for(i=0; i<size; i++)
		relationship[i] = 0;
	cout<<"Enter the [employee, manager] relation\n";
	for(i=0; i<size; i++){
		cin>>employee>>manager;
		relationship[manager-'A']++;		
	}
	for(i=0; i<size; i++){
		char x = 'A'+i;
		cout<<x<<":"<<relationship[i]<<"\n";
	}
return 0;
}

