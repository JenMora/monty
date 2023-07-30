#include "monty.h"

int c32_Er_NoInteger(unsigned int line_number);
int c5_file_open_error(char *filename); 
int c4_usage_error(void);
int c31_Er_malloc(void);
int c31_Er_op(char *opcode, unsigned int line_number);


/**
 * c4_usage_error - error message
 * Return: Exit status
 */
int c4_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * c31_Er_malloc - malloc Error
 * Return: Exit status
 */
int c31_Er_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * c5_file_open_error - error opening file
 * @filename: the file name
 * Return: exit failure
 */
int c5_file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * c31_Er_op - error in operations
 * @opcode: the code
 * @line_number: line number where error is
 * Return: exit failure
 */
int c31_Er_op(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * c32_Er_NoInteger - no error
 * @line_number: line number of error
 * Return: exit failure
 */
int c32_Er_NoInteger(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
