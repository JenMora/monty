#include "monty.h"

/**
 * pint -  A function that prints the value at the top of the stack
 * @stack: element at the top of the stack (last-in)
 * @mj_count: line count of the pint command in the monty file
 * Authors: Magdalene and Jeniffer
 * Return: 0, otherwise EXIT FAILURE
 */
void pint(mj_stack **stack, unsigned int mj_count)
{
	mj_stack *tmp = *stack;

	if (tmp != NULL)
	{
		printf("%d\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%u: The stack cannot be pinted\n", mj_count);
		error_signal = 1;
	}
}
