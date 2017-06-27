/*
Kahn's Algorithm:

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

    Increment count of visited nodes by 1.
    Decrease in-degree by 1 for all its neighboring nodes.
    If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.

Step 5: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int u, int v);
		void topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

// function to do topological sort
void Graph::topologicalSort(){

	// create a vector to store indegrees of all vertices. Initialise all indegrees as 0.
	vector<int> in_degree(V, 0);

	// traverse adjacency list to fill indegrees of vertices.
	for(int u=0; u<V; u++){
		list<int>::iterator itr;
		for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	// create a queue and enqueue all vertices with indegree 0
	queue<int> q;
	for(int i=0; i<V; i++)
		if(in_degree[i] == 0)
			q.push(i);

	// initialize count of visited vertices
	int cnt = 0;

	// create a vector to store topological ordering of vertices
	vector<int> top_order;

	// one by one dequeue vertices from queue and enqueue adjacents if indegree of adjacent is 0
	while(!q.empty()){
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// iterate through all its neighbouring nodes of dequeued node u and decrease their in-degree by 1
		list<int>::iterator itr;
		for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
			// if indegree becomes 0, add it to queue
			if(--in_degree[*itr] == 0)
				q.push(*itr);
			
		cnt++;
	}
	
	// check is there was a cycle
	if(cnt != V){
		cout<<"There exists a cycle in graph\n";
		return;
	}

	// print topological order
	for(int i=0; i<top_order.size(); i++)
		cout<<top_order[i]<<" ";
	cout<<"\n";
}

int main(){

    	Graph g(6);
    	g.addEdge(5, 2);
    	g.addEdge(5, 0);
    	g.addEdge(4, 0);
    	g.addEdge(4, 1);
    	g.addEdge(2, 3);
    	g.addEdge(3, 1);
 
    	cout << "Following is a Topological Sort of\n";
    	g.topologicalSort();

return 0;
}




