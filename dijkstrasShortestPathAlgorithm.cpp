// given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.

/*
Algorithm:
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSetand has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.
*/

#include <iostream>
#include <climits>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;

	for(int v = 0; v<V; v++){
		if(sptSet[v] == false && dist[v] <= min){
			min = dist[v];
			min_index = v;
		}	
	}
return min_index;
}

int printSolution(int dist[], int n){
	cout<<"vertex distance from source\n";
	for(int i=0; i<V; i++)
		cout<<i<<" "<<dist[i]<<"\n";
}

void dijkstra(int graph[V][V], int src){
	int dist[V];		// this will hold distance from src to i
	bool sptSet[V];		// sptSet[i] will be true if vertex i is included in spt or shortest distance from src to i is finalised
	for(int i=0; i<V; i++){
		dist[i] = INT_MAX;
		sptSet[i] = false;	
	}

	// distance of source vertex fro itself is always 0
	dist[src] = 0;

	// find shortest path for all vertices
	for(int count=0; count<V-1; count++){
		int u = minDistance(dist, sptSet);
		// mark picked vertex as processed
		sptSet[u] = true;
		for(int v=0; v<V; v++)
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
				dist[v] = dist[u]+graph[u][v];
	}

	// print constructed distance array
	printSolution(dist, V);
}

int main(){
   
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    	dijkstra(graph, 0);
  	return 0;
}


