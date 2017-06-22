// Given a list of tickets, find itinerary in order, it may be assumed that input list of tickets is not cyclic and there is one ticket from every city except final destination.

/* Algorithm
1) Create a HashMap of given pair of tickets.  Let the created 
   HashMap be 'dataset'. Every entry of 'dataset' is of the form 
   "from->to" like "Chennai" -> "Banglore"

2) Find the starting point of itinerary.
     a) Create a reverse HashMap.  Let the reverse be 'reverseMap'
        Entries of 'reverseMap' are of the form "to->form". 
 
     b) Traverse 'dataset'.  For every key of dataset, check if it
        is there in 'reverseMap'.  If a key is not present, then we 
        found the starting point. In the above example, "Bombay" is
        starting point.

3) Start from above found starting point and traverse the 'dataset' 
   to print itinerary.
*/

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

void printItinerary(map<string, string> dataSet){
	// to store reverse of given map
	map<string, string> reversemap;
	map<string, string>::iterator it;

	// to fill reverse map, iterate through the given map
	for(it = dataSet.begin(); it != dataSet.end(); it++)
		reversemap[it->second] = it->first;

	// find starting point of itinerary
	string start;

	for(it = dataSet.begin(); it != dataSet.end(); it++){
		if(reversemap.find(it->first) == reversemap.end()){
			start = it->first;
			break;
		}
	}

	if(start.empty()){
		cout<<"Invalid Input"<<"\n";
		return;
	}

	// once we have starting point, we can simply traverse
	it = dataSet.find(start);
	while(it != dataSet.end()){
		cout<<it->first<<"->"<<it->second<<"\n";
		it = dataSet.find(it->second);
	}
}

int main(){
	map<string, string> dataSet;
	dataSet["Chennai"] = "Bangalore";
	dataSet["Bombay"] = "Delhi";
	dataSet["Goa"] = "Chennai";
	dataSet["Delhi"] = "Goa";

	printItinerary(dataSet);

return 0;
}
