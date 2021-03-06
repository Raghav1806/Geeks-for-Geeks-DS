// Program to demonstrate adjacency list representation of graphs
#include <iostream>
#include <cstdlib>
using namespace std;

struct AdjListNode{
	int dest;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int V;
	struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest){
	struct AdjListNode *newNode = new AdjListNode;
	newNode->dest = dest;
	newNode->next = NULL;
return newNode;
}

struct Graph *createGraph(int V){
	struct Graph *graph = new Graph;
	graph->V = V;
	graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

	int i;
	for(i=0; i<V; i++)
		graph->array[i].head = NULL;
return graph; 
}

void addEdge(struct Graph *graph, int src, int dest){
	struct AdjListNode *newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// since graph is undirected, add an edge from dest to src as well
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void printGraph(struct Graph *graph){
	int v;
	for(v=0; v < graph->V; v++){
		struct AdjListNode *pCrawl = graph->array[v].head;
		cout<<"\nAdjacency list of vertex "<<v<<"\n";
		while(pCrawl){
			cout<<pCrawl->dest<<" ";
			pCrawl = pCrawl->next;
		}
	}
}

int main(){
    	
	int V = 5;
    	struct Graph* graph = createGraph(V);
    	addEdge(graph, 0, 1);
    	addEdge(graph, 0, 4);
    	addEdge(graph, 1, 2);
    	addEdge(graph, 1, 3);
    	addEdge(graph, 1, 4);
    	addEdge(graph, 2, 3);
    	addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}

