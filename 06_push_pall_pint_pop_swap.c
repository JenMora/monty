#include "monty.h"

void c14_op_push(stack_t **stack, unsigned int line_number);
void c15_op_pall(stack_t **stack, unsigned int line_number);
void c16_op_pint(stack_t **stack, unsigned int line_number);
void c17_op_pop(stack_t **stack, unsigned int line_number);
void c18_op_swap(stack_t **stack, unsigned int line_number);

/**
 * c14_op_push - pushes into stack
 * @stack: pinter to the pushed node
 * @line_number: line nimber
 */
void c14_op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		c13_token_opSet_Er(c31_Er_malloc());
		return;
	}
	if (c1_optokens[1] == NULL)
	{
		c13_token_opSet_Er(c32_Er_NoInteger(line_number));
		return;
	}
	for (i = 0; c1_optokens[1][i]; i++)
	{
		if (c1_optokens[1][i] == '-' && i == 0)
			continue;
		if (c1_optokens[1][i] < '0' || c1_optokens[1][i] > '9')
		{
			c13_token_opSet_Er(c32_Er_NoInteger(line_number));
			return;
		}
	}
	new->n = atoi(c1_optokens[1]);
	if (c10_check(*stack) == STACK)

	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * c15_op_pall - function to printd stack values
 * @stack: the stack
 * @line_number: the line number
 */
void c15_op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * c16_op_pint - pint function
 * @stack: the stack
 * @line_number: the line number
 */
void c16_op_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		c13_token_opSet_Er(c16_op_pint_err(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * c17_op_pop - removes elements from a stack
 * @stack: the stack
 * @line_number: the line number
 */
void c17_op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		c13_token_opSet_Er(c17_op_pop_err(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * c18_op_swap - swap elements of a stack
 * @stack: the stacl
 * @line_number: the line number
 */
void c18_op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
