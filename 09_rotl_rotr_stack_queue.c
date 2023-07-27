#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void sta_ck(stack_t **stack, unsigned int line_number);
void que_ue(stack_t **stack, unsigned int line_number);

/**
 * rotl - rotates the top to bottom
 * @stack: the stack
 * @line_number: the line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		return;
	}
	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
	{
		bottom = bottom->next;
	}

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}

/**
 * rotr - rotates too
 * @stack: the stack
 * @line_number: the line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	
}

/**
 * sta_ck - from queue to stack
 * @stack: the stack
 * @line_number: the line number
 */
void sta_ck(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = MJ_STACK;

	(void)line_number;
}

/**
 * que_ue - converts stack to queue
 * @stack: the stack
 * @line_number: the line number
 */
void que_ue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = MJ_QUEUE;

	(void)line_number;
}
