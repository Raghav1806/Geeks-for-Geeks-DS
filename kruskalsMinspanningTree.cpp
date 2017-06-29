/* 
Algorithm:

1. Sort all the edges in non-decreasing order of their weight.

2. Pick the smallest edge. Check if it forms a cycle with the spanning tree 
formed so far. If cycle is not formed, include this edge. Else, discard it.  

3. Repeat step#2 until there are (V-1) edges in the spanning tree.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

struct Edge{
	int src, dest, weight;
};

struct Graph{
	int V, E;
	struct Edge *edge;
};

struct Graph *createGraph(int V, int E){
	struct Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

return graph;
}

struct subset{
	int parent;	
	int rank;
};

// utility function to find set of an element i
int find(struct subset subsets[], int i){
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

return subsets[i].parent;
}

// function that does union of two sets of x and y
void Union(struct subset subsets[], int x, int y){
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// attach smaller rank tree under root of high rank tree
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// if ranks are same, then make one as root and increment its rank by one
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

// compare two edges according to their weights
int myCop(const void *a, const void *b){
	struct Edge *a1 = (struct Edge*)a;
	struct Edge *b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph){
	int V = graph->V;
	struct Edge result[V];
	int e = 0;	// index variable, used for result[]
	int i = 0;	// index variable, used for sorted edges

	// sort all edges in increasing order
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	// allocate memory for creating V subsets
	struct subset *subsets = (struct subset*)malloc(V*sizeof(struct subset));

	// create V subsets with single elements
	for(int v = 0; v < V; v++){
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	
	// number of edges to be taken is V-1
	while(e < V-1){
		// pick smallest edge, and increment for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// if including this edge doesn't cause cycle, include it
		if(x != y){
			result[e++] = next_edge;
			Union(subsets, x, y);
		}

		// else discard next_edge
	}

	cout<<"Following are the edges in the constructed MST\n";
    	for (i = 0; i < e; ++i)
        	cout<<result[i].src<<"\t"<<result[i].dest<<"\t"<<result[i].weight<<"\n";
    
return;
}

int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
 
    return 0;
}
