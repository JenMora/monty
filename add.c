#include "monty.h"

/**
 * add - A function that adds the top two elements of a stack
 * @stack: element at the top of the stack (last-in)
 * @mj_count: line count of the add command in the monty file
 * Authors: Magdalene and Jeniffer
 * Return: 0, otherwise EXIT FAILURE
 */
void add(mj_stack **stack, unsigned int mj_count)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: Stack too short for addition \n\n", mj_count);
		error_signal = 1;
	}
	else
	{
		(*stack)->prev->n = (*stack)->n + (*stack)->prev->n;
		pop(stack, mj_count);
	}
}
