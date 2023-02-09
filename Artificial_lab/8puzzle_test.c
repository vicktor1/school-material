#include <stdio.h>
#include <stdlib.h>

#define PUZZLE_ROW 3
#define PUZZLE_COL 3 
#define PUZZLE_SIZE (PUZZLE_COL * PUZZLE_ROW)

struct position {
	int coord_X;			// x coordinate for blank
	int coord_Y;			// y coordinate for blank
};

struct intermediate_node 
{
	char intermediate_state[PUZZLE_SIZE];	// store puzzle intermediate state
	struct position blank_position;			// store blank position
};

struct STACK_node {
	struct intermediate_node *bufptr;
	int count;					// we gone store count
	int size;
};

struct intermediate_node *allocate_node(char *state, struct position *blank_position)
{
	struct intermediate_node *newnode;

	// allocate new node with malloc(
	newnode = malloc(sizeof(struct intermediate_node));
	assert( newnode != NULL );


	// copy intermediate state
	memcpy(newnode->intermediate_state, state, sizeof(char) * PUZZLE_SIZE);
	// copy blank position
	memcpy(newnode->blank_position, blank_position, sizeof(struct position));

	return newnode;
}

int calculate_cost(struct intermediate* self, char* final_state)
{
	int count = 0;
	// if box value not equal to final-state value
	// then add one to its heuristics value
	for (int idx = 0; idx < PUZZLE_SIZE; idx++)
		if (self->intermediate_state[idx] != final_state[idx])
			count++;
	return count;
}


void solve(char* initial_state, char* final_state, struct position* blank_position)
{
	struct intermediate_node* newnode;
	struct 
	int cost;

	newnode = allocate_node(initial_state, blank_position);
	cost = calculate_cost(newnode, final_state);

	while (!)
	{

	}
}

int main(int argc, char* argv[])
{
	char initial_state[PUZZLE_SIZE] = {
		'1', '8', '2',
		'5', '_', '7',
		'3', '4', '6'
	}, 
	final_state[PUZZLE_SIZE] = {
		'1', '2', '3', 
		'4', '5', '6', 
		'7', '8', '_'
	};
	struct position blank_position = {
		.coord_X = 1,
		.coord_Y = 1
	};
	solve(initial_state, final_state, &blank_position);
	return 0;
}
