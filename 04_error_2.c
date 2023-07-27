#include "monty.h"

int stackError(unsigned int line_number, char *operat);
int division_error(unsigned int line_number);
int popError(unsigned int line_number);
int putcharError(unsigned int line_number, char *msg);

/**
 * popError - pop error message
 * @line_number: line number of error
 * Return: Exit failure
 */

int popError(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pintError - pint error
 * @line_number: the line number with error
 * Return: Exit failure
 */
int pintError(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * stackError - error in stacks
 * @line_number: the line number
 * @operat: the operator
 * Return: Error
 */
int stackError(unsigned int line_number, char *operat)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, operat);
	return (EXIT_FAILURE);
}

/**
 * division_error - error in division
 * @line_number: the line where error is
 * Return: Exit Failure
 */
int division_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * putcharError - putchar error
 * @line_number: line number where error is
 * @msg: the error message
 */
int putcharError(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
