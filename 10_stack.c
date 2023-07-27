#include "monty.h"
void mj_free_the_stack(stack_t **stack);
int initStack(stack_t **stack);
int checkMonty(stack_t *stack);

/**
 * mj_free_the_stack - frees stack
 * @stack: the stack
 */
void mj_free_the_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);

		*stack = tmp;
	}
}

/**
 * initStack - initializes nodes
 * @stack: the stack
 * Return: success or failure
 */
int initStack(stack_t **stack)
{
	stack_t *t;

	t = malloc(sizeof(stack_t));

	if (t == NULL)
		return (mallocError());
	t->n = MJ_STACK;
	t->prev = NULL;
	t->next = NULL;
	*stack = t;

	return (EXIT_SUCCESS);
}

/**
 * checkMonty - checks for links and queue
 * @stack: the stack
 * Return: 2, MJ_STACK, MJ_QUEUE
 */
int checkMonty(stack_t *stack)
{
	if (stack->n == MJ_STACK)
		return (MJ_STACK);
	else if (stack->n == MJ_QUEUE)
		return (MJ_QUEUE);
	
	
	return (2);
}
