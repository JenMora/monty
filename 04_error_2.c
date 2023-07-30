#include "monty.h"

int c29_op_stack_err(unsigned int line_number, char *op);
int c22_op_div_err(unsigned int line_number);
int c17_op_pop_err(unsigned int line_number);
int c32_Er_putchar(unsigned int line_number, char *msg);

/**
 * c17_op_pop_err - pop error message
 * @line_number: line number of error
 * Return: Exit failure
 */
int c17_op_pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * c16_op_pint_err - pint error
 * @line_number: the line number with error
 * Return: Exit failure
 */
int c16_op_pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * c29_op_stack_err - error in stacks
 * @line_number: the line number
 * @op: the operator
 * Return: Error
 */
int c29_op_stack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * c22_op_div_err - error in division
 * @line_number: the line where error is
 * Return: Exit Failure
 */
int c22_op_div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * c32_Er_putchar - putchar error
 * @line_number: line number where error is
 * @msg: the error message
 * Return: Exit Stat
 */
int c32_Er_putchar(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
