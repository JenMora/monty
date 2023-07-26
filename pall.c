#include "monty.h"

/**
 * pall - A function that prints the elements of a
 * stack in the monty interpreter
 * @stack: element at the top of the stack (last-in)
 * @mj_count: line count of the command in the monty file
 * Authors: Magdalene and Jeniffer
 * Return: 0 on success, otherwise EXIT FAILURE
 */
void pall(mj_stack **stack, unsigned int mj_count)
{
	mj_stack *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	(void)mj_count;
}
