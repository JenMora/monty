#include "monty.h"

void mj_pop(stack_t **stack, unsigned int ln_num)
{
	stack_t *mj_tmp;


	if (!*stack)
	{
		fprintf(stderr, "L%d: can't mj_pop an empty stack\n", ln_num);
		exit(EXIT_FAILURE);
	}
	mj_tmp = *stack;
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(mj_tmp);
}
