#include "monty.h"
#include <string.h>

void c8_free_stk(stack_t **stack);
int c9_init(stack_t **stack);
int c10_check(stack_t *stack);

/**
 * c8_free_stk - frees stack
 * @stack: the stack
 */
void c8_free_stk(stack_t **stack)
{
	stack_t *tmp;

	tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * c9_init - initializes nodes
 * @stack: the stack
 * Return: success or failure
 */
int c9_init(stack_t **stack)
{
	stack_t *t;

	t = malloc(sizeof(stack_t));
	if (t == NULL)
		return (c31_Er_malloc());
	t->n = STACK;
	t->prev = NULL;
	t->next = NULL;
	*stack = t;
	return (EXIT_SUCCESS);
}

/**
 * c10_check - checks for links and queue
 * @stack: the stack
 * Return: 2, MJ_STACK, MJ_QUEUE
 */
int c10_check(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
