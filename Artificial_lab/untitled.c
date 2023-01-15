// Find the goalnode & the # paths towards goalnode
// shortest path

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
	struct string edges;
	bool visited;
};

// we love vector
struct string {
	char* c_str;
	int size;
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
			printf("\n");
			stack_pop(&intstack);
		}
		else
		{
			graph[unvisited].visited = true;
			stack_push(&intstack, unvisited);
		}
	}
}


void init_string(struct string* self, const char* str)
{
	self->c_str = str;
	self->size = strlen(str);
}

int main(int argc, char *argv[])
{
	struct node graph[] = {
		{'A', false, 0},
		{'B', false, 0},
		{'C', false, 0},
		{'D', false, 0},
		{'E', false, 0},
		{'F', false, 0},
		{'G', false, 0},
		{'H', false, 0}
	};


	// gen_rep_graph(graph, array_size(graph)))

	dfs(graph, array_size(graph));
	return 0;
}
