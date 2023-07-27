#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)
{
     stack_t *temp;
	
	if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;

    if ((*stack)->next)
    {
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
    }
    else
    {
        *stack = NULL;
    }

    free(temp);
}

