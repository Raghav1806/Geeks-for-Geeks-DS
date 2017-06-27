// program to detect cycle in a directed graph using colors

/* 
Algorithm:
WHITE : Vertex is not processed yet. Initially
        all vertices are WHITE.

GRAY : Vertex is being processed (DFS for this 
       vertex has started, but not finished which means
       that all descendants (in DFS tree) of this vertex
       are not processed yet (or this vertex is in function
       call stack)

BLACK : Vertex and all its descendants are 
        processed.

While doing DFS, if we encounter an edge from current 
vertex to a GRAY vertex, then this edge is back edge 
and hence there is a cycle.
*/

#include <iostream>
#include <list>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

class Graph{
	int V;
	list<int> *adj;
	bool DFSUtil(int v, int color[]);

	public:
		Graph(int V);
		void addEdge(int v, int w);
		bool isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

// recursive function to find if there is back edge in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[]){
	color[u] = GRAY;
	
	list<int>::iterator i;
	for(i=adj[u].begin(); i != adj[u].end(); i++){
		int v = *i;	// an adjacent of u
		if(color[v] == GRAY)
			return true;

		// if v is not processed and there is a back edge in subtree rooted with v
		if(color[v] == WHITE && DFSUtil(v, color))
			return true;
	}

	color[u] = BLACK;
return false;
}

bool Graph::isCyclic(){
	int *color = new int[V];
	for(int i=0; i<V; i++)
		color[i] = WHITE;

	// do a DFS traversal beginning with all vertices
	for(int i=0; i<V; i++)
		if(color[i] == WHITE)
			if(DFSUtil(i, color) == true)
				return true;
return false;
}

int main(){
    
	Graph g(4);
    	g.addEdge(0, 1);
    	g.addEdge(0, 2);
    	g.addEdge(1, 2);
    	g.addEdge(2, 0);
    	g.addEdge(2, 3);
    	g.addEdge(3, 3);
 
    	if (g.isCyclic())
        	cout << "Graph contains cycle";
    	else
        	cout << "Graph doesn't contain cycle";

return 0;
}


