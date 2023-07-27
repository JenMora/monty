#include "monty.h"

void mj_add(stack_t **stack, unsigned int ln_num)
{
	int mjSum;
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mj_add, stack too short\n", ln_num);
		exit(EXIT_FAILURE);
	}


	mjSum = (*stack)->n + (*stack)->next->n;
	tmp = (*stack)->next;
	(*stack)->next->n = mjSum;
	(*stack)->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = *stack;

	free(tmp);
}
