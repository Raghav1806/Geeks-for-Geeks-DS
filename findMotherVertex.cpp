// A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.

/* 
Algorithm:
(1) Do DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’. This step takes O(V+E) time.
(2) If there exist mother vertex (or vetices), then v must be one (or one of them). Check if v is a mother vertex by doing DFS/BFS from v. This step also takes O(V+E) time.
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int v, vector<bool> &visited);

	public:
		Graph(int V);
		void addEdge(int v, int w);
		int findMother();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

// a recursive function to print DFS starting from v
void Graph::DFSUtil(int v, vector<bool> &visited){
	visited[v] = true;

	// recur for all vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++)
		if(!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

int Graph::findMother(){
	// visited[] is used for DFS, intitially all are intitialized as not visited
	vector<bool> visited(V, false);

	// to store last finished vertex, or mother vertex
	int v = 0;

	// Do a DFS traversal and find last finished vertex
	for(int i = 0; i < V; i++){
		if(visited[i] == false){
			DFSUtil(i, visited);
			v = i;
		}
	} 
	// if there exist mother vertex (or vertices) in given graph, then v must be one (or more) of them
	// check if every vertex is reachable from v or not
	// reset all values in visited[] as false and doDFS beginning from v to check if all vertices are reachable from it or not
	fill(visited.begin(), visited.end(), false);
	DFSUtil(v, visited);
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			return -1;
	return v;
}

int main(){
    	Graph g(7);
    	g.addEdge(0, 1);
    	g.addEdge(0, 2);
    	g.addEdge(1, 3);
    	g.addEdge(4, 1);
    	g.addEdge(6, 4);
    	g.addEdge(5, 6);
    	g.addEdge(5, 2);
    	g.addEdge(6, 0);
 
    	cout << "A mother vertex is " << g.findMother();
return 0;
}

