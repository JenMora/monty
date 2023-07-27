#include "monty.h"

void mj_push_nod(stack_t **stack, int n);

void push(stack_t **stack, unsigned int ln_num)
{
	char *arg = strtok(NULL, " \n");
	int n;

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln_num);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	mj_push_nod(stack, n);
}

void mj_push_nod(stack_t **stack, int n)
{
	stack_t *nodNew = malloc(sizeof(stack_t));

	if (!nodNew)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nodNew->n = n;
	nodNew->prev = NULL;

	if (!*stack)
	{
		nodNew->next = NULL;
	}
	else
	{
		nodNew->next = *stack;
		(*stack)->prev = nodNew;
	}

	*stack = nodNew;
}
