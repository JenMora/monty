#include "monty.h"

void mj_pall(stack_t **stack, unsigned int ln_num)
{
	stack_t *node_in_use = *stack;

	while (node_in_use)
	{
		printf("line %u: %d\n", ln_num, node_in_use->n);
		node_in_use = node_in_use->next;
	}
}
