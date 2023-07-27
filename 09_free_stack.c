#include "monty.h"

void free_stack(stack_t **stack)
{
	stack_t *node_in_use = *stack;
	stack_t *next;

	while (node_in_use)
	{
		next = node_in_use->next;
		free(node_in_use);
		node_in_use = next;
	}
	*stack = NULL;
}
