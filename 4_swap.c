#include "monty.h"
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *second;
	
	if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    second = (*stack)->next;
    (*stack)->next = second->next;
    second->next = *stack;
    *stack = second;
}

