#include "monty.h"

int monty_stack_err(unsigned int line_number, char *op);
int monty_div_err(unsigned int line_number);
int monty_pop_err(unsigned int line_number);
int pchar_error(unsigned int line_number, char *msg);

/**
 * monty_pop_err - A function that prints pop error msgs for empty
 * stacks in .m files
 * @line_number: Line number in script where error occured in a .m file
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * monty_pint_err - A function that prints pint error msgs for
 * empty stacks in .m files
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * monty_stack_err -  A function that prints monty math function error msgs
 *                     for stacks/queues smaller than two nodes in .m files
 * @line_number: Line number in Monty bytecodes file where an error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_stack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * monty_div_err - A function that prints division error msgs for
 * division by 0 in .m files
 * @line_number: Line number in Monty bytecodes file where an error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error -  A function that prints pchar error msgs for empty stacks
 *               empty stacks and non-character values in .m files
 * @line_number:  The line number in Monty bytecodes file where error occurred.
 * @msg: The error msg to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}

