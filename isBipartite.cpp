// check whether a given graph is bipartite or not [this code worksfor disconnected graph also]

/*
Algorithm:
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
1. Assign RED color to the source vertex (putting into set U).
2. Color all the neighbors with BLUE color (putting into set V).
3. Color all neighbor’s neighbor with RED color (putting into set U).
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 
*/

#include <iostream>
#include <queue>
using namespace std;

const int V = 4;

bool isBipartiteUtil(int G[][V], int src, int colorArr[]){
	colorArr[src] = 1;
	// create a queue of vertex numbers and enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	//  run while there are vertices in queue
	while(!q.empty()){
		int u = q.front();
		q.pop();

		// find all non-colored adjacent vertices
		for(int v=0; v<V; v++){
			// an edge fro u to v exists and v is not colored
			if(G[u][v] && colorArr[v] == -1){
				// assign alternate color to this adjacent v of u
				colorArr[v] = 1-colorArr[u];
				q.push(v);
			}

			// an edge from u to v exists and destination v is colored with same color as u
			else if(G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	// if we reach here, then all adjacent vertices can be colored with alternate color
	return true;
}

bool isBipartite(int G[][V]){
	// value '-1' indicates no color, 1 is used to indicate first color, 0 is used to indicate second color
	int colorArr[V];

	for(int i=0; i<V; i++)
		colorArr[i] = -1;

	// this code is used to handle disconnected graph
	for(int i=0; i<V; i++)
		if(colorArr[i] == -1)
			if(isBipartiteUtil(G, i, colorArr) == false)
				return false;
return true;
}

int main(){
    
	int G[][V] = {{0, 1, 0, 1},
        	{1, 0, 1, 0},
        	{0, 1, 0, 1},
        	{1, 0, 1, 0}
    	};
 
    	isBipartite(G) ? cout << "Yes" : cout << "No";
    	return 0;
}
