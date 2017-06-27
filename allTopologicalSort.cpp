// program to print all topological sorts of a graph
#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	vector<int> indegree;
	void allTopologicalSortUtil(vector<int> &res, bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void allTopologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];

	// initializing all indegree with 0
	for(int i=0; i<V; i++)
		indegree.push_back(0);
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	indegree[w]++;
}

void Graph::allTopologicalSortUtil(vector<int> &res, bool visited[]){
	// to indicate whether all topological are found or not
	bool flag = false;
	for(int i=0; i<V; i++){
		// if indegree is 0 and not yet visited, then only choose that vertex
		if(indegree[i] == 0 && !visited[i]){
			// reducing indegree of adjacent vertices
			list<int>:: iterator j;
			for(j=adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]--;

			// including in result
			res.push_back(i);
			visited[i] = true;
			allTopologicalSortUtil(res, visited);

			// resetting visited, res and indegree for backtracking
			visited[i] = false;
			res.erase(res.end()-1);
			for(j=adj[i].begin(); j!=adj[i].end(); j++)
				indegree[*j]++;

			flag = true;
		}
	}

	// we reach here if all vertices are visited
	if(!flag){
		for(int i=0; i<res.size(); i++)
			cout<<res[i]<<" ";
		cout<<"\n";
	}
}

void Graph::allTopologicalSort(){
	// mark all vertices as not visited
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
		visited[i] = false;

	vector<int> res;
	allTopologicalSortUtil(res, visited);
}

int main(){
    	Graph g(6);
    	g.addEdge(5, 2);
    	g.addEdge(5, 0);
    	g.addEdge(4, 0);
    	g.addEdge(4, 1);
    	g.addEdge(2, 3);
    	g.addEdge(3, 1);
 
    	cout << "All Topological sorts\n";
 
    	g.allTopologicalSort();

return 0;
}
