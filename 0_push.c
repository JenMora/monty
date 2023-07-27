#include "monty.h"

void push_node(stack_t **stack, int n);

void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int n;
    
    if (!arg || !isdigit(*arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    push_node(stack, n);
}

void push_node(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (!*stack)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
