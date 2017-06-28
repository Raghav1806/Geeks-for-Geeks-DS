// Given a graph G and an integer K, K-cores of the graph are connected components that are left after all vertices of degree less than k have been removed.

/* 
Algorithm:
To implement above algorithm, we do a modified DFS on the input graph and delete all the vertices having degree less than ‘K’, then update degrees of all the adjacent vertices, and if their degree falls below ‘K’ we will delete them too.
*/

#include <iostream>
#include <list>
#include <vector>
#include <climits>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int u, int v);
		// a recursive function to print DFS starting from v
		bool DFSUtil(int, vector<bool> &, vector<int> &, int k);

		// print k-cores of given graph
		void printKCores(int k);
};

// a recursive function to print DFS starting from v.
// returns true if degree of v after processing is less than k else false
// updates degree of adjacent vertices
bool Graph::DFSUtil(int v, vector<bool> &visited, vector<int> &vDegree, int k){
	// mark current node as visited
	visited[v] = true;

	// recur for all vertices adjacent to this vertex
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++){
		if(vDegree[v] < k)
			vDegree[*i]--;
		// if adjacent is not processed, process it
		if(!visited[*i]){
			// if degree of adjacent after processing becomes less than k, then reduce degree of v also
			if(DFSUtil(*i, visited, vDegree, k))
				vDegree[v]--;
		}
	}

	// return true if degree of v is less than k
	return(vDegree[v] < k);
}

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// print k cores of an undirected graph
void Graph::printKCores(int k){
	// mark all vertices as not visited and not processed
	vector<bool> visited(V, false);
	vector<bool> processed(V, false);

	int mindeg = INT_MAX;
	int startvertex;
	
	// store degrees of all vertices
	vector<int> vDegree(V);
	for(int i = 0; i < V; i++){
		vDegree[i] = adj[i].size();
		if(vDegree[i] < mindeg){
			mindeg = vDegree[i];
			startvertex = i;
		}
	}

	DFSUtil(startvertex, visited, vDegree, k);

	// DFS traversal to update degrees of all vertices
	for(int i = 0; i < V; i++)
		if(visited[i] == false)
			DFSUtil(i, visited, vDegree, k);

	// printing K cores
	cout<<"K-Cores : \n";
	for(int v = 0; v < V; v++){
		if(vDegree[v] >= k){
			cout<<"\n["<<v<<"]";

			// traverse adjacency list of v and print only those adjacent vertices which have vDegree >= k after DFS
			list<int>::iterator itr;
			for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
				if(vDegree[*itr] >= k)
					cout<<" -> "<<*itr;
			}	
		}
	}
}

int main(){

    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);
 
    cout << endl << endl;
 
    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);
    g2.printKCores(k);
 
    return 0;
}

