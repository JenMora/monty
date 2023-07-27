#include "monty.h"

void nop(stack_t **stack, unsigned int line_number);
void put_char(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/**
 * nop - function des nothing
 * @stack: the stack
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * put_char - prints the top value
 * @stack: the stack
 * @line_number: the line number
 */
void put_char(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		setOprationTokenError(putcharError(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		setOprationTokenError(putcharError(line_number,
					"value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * pstr - string contained in stack
 * @stack: the stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	(void)line_number;
}
