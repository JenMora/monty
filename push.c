#include "monty.h"

/**
 * push - A function that adds a node to the stack(to the last-in)
 * @stack: element at the top of the stack
 * @mj_count: line count of the command in the monty file
 * Authors: Magdalene and Jeniffer
 * Return: 0, otherwise EXIT FAILURE
 */
void push(mj_stack **stack, unsigned int mj_count)
{
	mj_stack *mj_new_node;

	if (args[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", mj_count);
		error_signal = 1;
	}
	else
	{
		global_count = atoi(args[1]);
		mj_new_node = (mj_stack *)malloc(sizeof(mj_stack));
		if (global_count == 0 && strcmp(args[1],
			"0") != 0 && strcmp(args[1], "-0") != 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", mj_count);
			error_signal = 1;
			free(mj_new_node);
		}
		else if (mj_new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failure\n");
			error_signal = 1;
		}
		else
		{
			mj_new_node->n = global_count;
			mj_new_node->next = NULL;
			mj_new_node->prev = NULL;
			if (*stack == NULL)
			{
				*stack = mj_new_node;
			}
			else
			{
				(*stack)->next = mj_new_node;
				mj_new_node->prev = *stack;
				*stack = mj_new_node;
			}
		}
	}
}

