#include "monty.h"

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/**
 * add - adds the two top value
 * @stack: the stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * sub - removes second value from stack
 * @stack: the stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "sub"));
		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * monty_div - divides the 2ns element by 1st
 * @stack: the stack
 * @line_number: the line number
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		setOprationTokenError(division_error(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies 2nd value by 1st value
 * @stack: the stack
 * @line_number: the line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * mod - mods 2nd to 1st
 * @stack: the stack
 * @line_number: the line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		setOprationTokenError(division_error(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
