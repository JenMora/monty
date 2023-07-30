#include "monty.h"

void c21_op_nop(stack_t **stack, unsigned int line_number);
void c25_op_putchar(stack_t **stack, unsigned int line_number);
void c26_op_pstr(stack_t **stack, unsigned int line_number);

/**
 * c21_op_nop - function des nothing
 * @stack: the stack
 * @line_number: the line number
 */
void c21_op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * c25_op_putchar - prints the top value
 * @stack: the stack
 * @line_number: the line number
 */
void c25_op_putchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		c13_token_opSet_Er(c32_Er_putchar(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		c13_token_opSet_Er(c32_Er_putchar(line_number,
					     "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * c26_op_pstr - string contained in stack
 * @stack: the stack
 * @line_number: the line number
 */
void c26_op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
