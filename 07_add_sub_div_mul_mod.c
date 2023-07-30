#include "monty.h"

void c19_op_add(stack_t **stack, unsigned int line_number);
void c20_op_sub(stack_t **stack, unsigned int line_number);
void c22_op_div(stack_t **stack, unsigned int line_number);
void c23_op_mul(stack_t **stack, unsigned int line_number);
void c24_op_mod(stack_t **stack, unsigned int line_number);

/**
 * c19_op_add - adds the two top value
 * @stack: the stack
 * @line_number: the line number
 */
void c19_op_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	c17_op_pop(stack, line_number);
}

/**
 * c20_op_sub - removes second value from stack
 * @stack: the stack
 * @line_number: the line number
 */
void c20_op_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	c17_op_pop(stack, line_number);
}

/**
 * c22_op_div - divides the 2ns element by 1st
 * @stack: the stack
 * @line_number: the line number
 */
void c22_op_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		c13_token_opSet_Er(c22_op_div_err(line_number));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	c17_op_pop(stack, line_number);
}

/**
 * c23_op_mul - multiplies 2nd value by 1st value
 * @stack: the stack
 * @line_number: the line number
 */
void c23_op_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	c17_op_pop(stack, line_number);
}

/**
 * c24_op_mod - mods 2nd to 1st
 * @stack: the stack
 * @line_number: the line number
 */
void c24_op_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		c13_token_opSet_Er(c29_op_stack_err(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		c13_token_opSet_Er(c22_op_div_err(line_number));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	c17_op_pop(stack, line_number);
}
