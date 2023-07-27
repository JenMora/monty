#include "monty.h"
#include <string.h>

void monty_free_stack(stack_t **stack);
int monty_monty_init_stack(stack_t **stack);
int monty_check_mode(stack_t *stack);

/**
 * monty_free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void monty_free_stack(stack_t **stack)
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
 * monty_monty_init_stack - A function that iInitializes a stack_t
 * stack with beginning stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int monty_monty_init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (monty_malloc_err());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * monty_check_mode  - A function that checks if a stack_t linked list is in
 * stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int monty_check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

