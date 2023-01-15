// Implementation of BFS traversal on Graph
// Pseudocode
/*
 * // Breadth_First_Search(Graph, x)
 * // Here, Graph is the graph that we already have and X is the source node
 * // 
 *
 * // Let Q be the queue
 * Q enqueue(x) 		// inserting source node X into the queue
 *
 * // Mark X node as visited
 *
 * while (Q is not empty)
 * 	Y = Q.dequeue() 		// Removing the front node from the queue
 *
 * 	Process all the neighbors of Y, For all the neighbors Z of Y
 * 	If Z is not visited, Q.enqueue(Z)		// Store Z in Q
 * 	Mark Z as visited 
 *
 * 	Follow the below method to implement BFS traversal
 *
 * 	Declare a queue and insert the starting vertex
 * 	Initialize a visited array and mark the starting vertex as visited
 * 	Follow the below process till the queue becomes empty
 *
 * 		- Remove the first vertex of the queue
 * 		- Mark that vertex as visited
 * 		- Insert all the unvisited neighbors of the vertex into the queue.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_VERTICES 50

typedef struct {
	int V;	// no of vertices
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// constructor 
Graph* Graph_create(int V)
{
	Graph *g = (Graph *)malloc(sizeof(Graph));
	assert (g != NULL);

	g->V = V;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			g->adj[i][j] = false;

	return g;
}


// Destructor
void Graph_destroy(Graph *g) { free(g); }

// Function to add edges to graph
void Graph_addEdge(Graph *g, int v, int w)
{
	g->adj[v][w] = true;		// Add w to v's list
}

// prints BFS traversal from a given source s
void Graph_BFS(Graph *g, int s) 
{
	// Mark all the vertices as not visited
	bool visited[MAX_VERTICES];
	int queue[MAX_VERTICES], front = 0, rear = 0; // Create a queue for BFS

	memset(visited, 0, sizeof(visited));

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) 
	{
		// Dequeue a vertex from queue and print it
		s = queue[front++];
		printf("%d -> ", s);


		// Get all adjacent vertices of the dequeueed
		// vertex s. If a adjacent has not been visited then
		// mark it visited and enqueue it.
		for (int adjacent = 0; adjacent < g->V; adjacent++)
		{
			if (g->adj[s][adjacent] && !visited[adjacent]) 
			{
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
	printf("\n");
}

// Driver program to test methods of graph struct
int main(int argc, char* argv[])
{
	// Create a graph given in the above diagram
	Graph *g = Graph_create(4);

	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is Breadth First Traversal "
			"(starting from vertex 2) \n");

	Graph_BFS(g, 2);
	Graph_destroy(g);

	return 0;
}

