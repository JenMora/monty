#include "monty.h"

int noInternalError(unsigned int line_number);
int fileOpenError(char *filename);
int montyRunError(void);
int mallocError(void);
int montyOperationError(char *opcode, unsigned int line_number);

/**
 * montyRunError - error message
 * Return: Exit status
 */

int montyRunError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * mallocError - malloc Error
 * Return: Exit status
 */

int mallocError(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * fileOpenError - error opening file
 * @filename: the file name
 * Return: exit failure
 */
int fileOpenError(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * montyOperationError - error in operations
 * @opcode: the code
 * @line_number: line number where error is
 * Return: exit failure
 */

int montyOperationError(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * noInternalError - no error
 * @ine_number: line number of error
 * Return: exit failure
 */
int noInternalError(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
