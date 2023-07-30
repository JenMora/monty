#include "monty.h"

void c27_op_rotl(stack_t **stack, unsigned int line_number);
void c28_op_rotr(stack_t **stack, unsigned int line_number);
void c29_op_stack(stack_t **stack, unsigned int line_number);
void c30_op_queue(stack_t **stack, unsigned int line_number);

/**
 * c27_op_rotl - rotates the top to bottom
 * @stack: the stack
 * @line_number: the line number
 */
void c27_op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
stack_t *bottom;

(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}

/**
 * c28_op_rotr - rotates too
 * @stack: the stack
 * @line_number: the line number
 */
void c28_op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *bottom;

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
 * c29_op_stack - from queue to stack
 * @stack: the stack
 * @line_number: the line number
 */
void c29_op_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * c30_op_queue - converts stack to queue
 * @stack: the stack
 * @line_number: the line number
 */
void c30_op_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
