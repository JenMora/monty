#include "monty.h"

/**
 * pop - A function that deletes the value at the top of stack (last-in)
 * @stack: element at the top of the stack (last-in)
 * @mj_count: line count of the pop command in the monty file
 * Authors: Magdalene and Jeniffer
 * Return: 0, otherwise EXIT FAILURE
 */
void pop(mj_stack **stack, unsigned int mj_count)
{
	mj_stack *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: This stack cannot be popped\n", mj_count);
		error_signal = 1;
	}
	else
	{
		*stack = (*stack)->prev;
		if ((*stack) != NULL)
		{
			(*stack)->next = NULL;
		}
		free(tmp);
	}
}
