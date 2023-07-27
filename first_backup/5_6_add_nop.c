#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
    int sum;
    stack_t *tmp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;
    tmp = (*stack)->next;
    (*stack)->next->n = sum;
    (*stack)->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = *stack;
    free(tmp);
}

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    UNUSED(stack);
    UNUSED(line_number);
}
