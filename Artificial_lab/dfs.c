#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/uio.h>
#include "stack.h"

#define array_size(array) (sizeof(array)/sizeof(*array))
struct node 
{
	char node_label;
	char* edges;
	bool visited;
};

void dfs(struct node graph[], int size)
{
	struct stack intstack = { 0 };
	int idx, unvisited, peekedValue;

	// push 0
	stack_push(&intstack, 0);
	graph[0].visited = true;

	while (!stack_empty(&intstack))
	{
		unvisited = -1;
		peekedValue = stack_peek(&intstack);

		for (idx = 0; graph[peekedValue].edges[idx] != '\0'; idx++)
		{
			if ( graph[graph[peekedValue].edges[idx]-0x41].visited == false)
			{
				unvisited = graph[peekedValue].edges[idx]-0x41;
				break;
			}
		}

		if (unvisited == -1)
		{
			for (int idx = 0; idx < intstack.count; idx++)
					printf("%c -> ", intstack.buf[idx]+0x41);
			stack_pop(&intstack);
		}
		else
		{
			graph[unvisited].visited = true;
			stack_push(&intstack, unvisited);
		}
	}
}

int main(int argc, char *argv[])
{
	struct node graph[] = {
		{'A', "BC"	, false},
		{'B', "DA"	, false},
		{'C', ""	, false},
		{'D', "EF"	, false},
		{'E', "G" 	, false},
		{'F', ""	, false},
		{'G', "H"	, false},
		{'H', ""	, false}
	};
	// gen_rep_graph(graph, array_size(graph)))
	dfs(graph, array_size(graph));
	return 0;
}
