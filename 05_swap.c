#include "monty.h"

void mj_swap(stack_t **stack, unsigned int ln_num)
{
	stack_t *stackTwo;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mj_swap, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}

	stackTwo = (*stack)->next;
	(*stack)->next = stackTwo->next;
	stackTwo->next = *stack;
	*stack = stackTwo;
}
