#include "monty.h"

void mj_pint(stack_t **stack, unsigned int ln_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't mj_pint, stack empty\n", ln_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
