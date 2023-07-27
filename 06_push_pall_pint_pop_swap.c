#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
 * push - pushes into stack
 * @stack: pinter to the pushed node
 * @line_number: line nimber
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *newNode;
	int i;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		setOprationTokenError(mallocError());
		return;	
	}
	if (token_operators[1] == NULL)
	{
		setOprationTokenError(noInternalError(line_number));
		return;
	}
	for (i = 0; token_operators[1][i]; i++)
	{
		if (token_operators[1][i] == '-' && i == 0)
			continue;
		if (token_operators[1][i] < '0' || token_operators[1][i] > '9')
		{
			setOprationTokenError(noInternalError(line_number));
			return;
		}
		
	}
	newNode->n = atoi(token_operators[1]);
	if (checkMonty(*stack) == MJ_STACK)
	{
		tmp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = tmp;
		if (tmp)
			tmp->prev = newNode;
		(*stack)->next = newNode;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		newNode->prev = tmp;
		newNode->next = NULL;
		tmp->next = newNode;
	}
}

/**
 * pall - function to printd stack values
 * @stack: the stack
 * @line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * pint - pint function
 * @stack: the stack
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		setOprationTokenError(pintError(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - removes elements from a stack
 * @stack: the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		setOprationTokenError(popError(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap - swap elements of a stack
 * @stack: the stacl
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOprationTokenError(stackError(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
