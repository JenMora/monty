#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;


    while (current)
    {
        printf("line %u: %d\n", line_number, current->n);
        current = current->next;
    }
}

