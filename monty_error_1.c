#include "monty.h"

int no_int_error(unsigned int line_number);
int f_open_error(char *filename);
int monty_usg_err(void);
int monty_malloc_err(void);
int monty_op_err(char *opcode, unsigned int line_number);


/**
 * monty_usg_err -  A function that prints usage error msgs in .m files
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_usg_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * monty_malloc_err - A function that prints malloc error msgs.
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - A function that prints file opening error msgs in .m files
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * monty_op_err - A file that prints unknown instruction error msgs in .m files
 * @opcode: Opcode where an  error occurred.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int monty_op_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - A function that prints invalid monty_push
 * argument error msgs.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

