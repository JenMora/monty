#define _POSIX_C_SOURCE 200809L
#include "monty.h"

#include <stdio.h>
#include <string.h>

void c11_free_tokens(void);
unsigned int c12_token_length_Er(void);
int c39_is_blank(char *line, char *c7_delimiter);
void (*c40_opcode(char *opcode))(stack_t**, unsigned int);
int c6_execute_mty(FILE *c2_file_dir);


/**
 * c11_free_tokens - frees tokens
 */
void c11_free_tokens(void)
{
	size_t i = 0;

	if (c1_optokens == NULL)
		return;

	for (i = 0; c1_optokens[i]; i++)
		free(c1_optokens[i]);

	free(c1_optokens);
}
/**
 * c12_token_length_Er - checks token length
 * Return: length
 */
unsigned int c12_token_length_Er(void)
{
	unsigned int len_of_tok = 0;

	while (c1_optokens[len_of_tok])
		len_of_tok++;
	return (len_of_tok);
}
/**
 * c39_is_blank - is the like blank?
 * @line: the line
 * @c39_is_blank: does it have a delimeter?
 * Return: -1 or 0
 */
int c39_is_blank(char *line, char *c7_delimiter)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; c7_delimiter[j]; j++)
		{
			if (line[i] == c7_delimiter[j])
				break;
		}
		if (c7_delimiter[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * c40_opcode - checks operator
 * @opcode: the matching operator
 * Return: pointer to operator
 */
void (*c40_opcode(char *opcode))(stack_t**, unsigned int)
{
	instruction_t c41_operator_functions[] = {
		{"push", c14_op_push},
		{"pall", c15_op_pall},
		{"pint", c16_op_pint},
		{"pop", c17_op_pop},
		{"swap", c18_op_swap},
		{"add", c19_op_add},
		{"nop", c21_op_nop},
		{"sub", c20_op_sub},
		{"div", c22_op_div},
		{"mul", c23_op_mul},
		{"mod", c24_op_mod},
		{"pchar", c25_op_putchar},
		{"pstr", c26_op_pstr},
		{"rotl", c27_op_rotl},
		{"rotr", c28_op_rotr},
		{"stack", c29_op_stack},
		{"queue", c30_op_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; c41_operator_functions[i].opcode; i++)
	{
		if (strcmp(opcode, c41_operator_functions[i].opcode) == 0)
			return (c41_operator_functions[i].f);
	}

	return (NULL);
}

/**
 * c6_execute_mty - execute
 * @c2_file_dir: the file script to run
 * Return: Exit success or failure
 */
int c6_execute_mty(FILE *c2_file_dir)
{
	void (*op_func)(stack_t**, unsigned int);
	
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, c42_status_of_exit = EXIT_SUCCESS;
	unsigned int line_number = 0;
	unsigned int prev_tLen = 0;
	
	if (c9_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, c2_file_dir) != -1)
	{
		line_number++;
		c1_optokens = c33_str_tow(line, C7_DELIMITER);
		if (c1_optokens == NULL)
		{
			if (c39_is_blank(line, C7_DELIMITER))
				continue;
			c8_free_stk(&stack);
			return (c31_Er_malloc());
		}
		else if (c1_optokens[0][0] == '#')
		{
			c11_free_tokens();
			continue;
		}
		op_func = c40_opcode(c1_optokens[0]);
		if (op_func == NULL)
		{
			c8_free_stk(&stack);
			c42_status_of_exit = c31_Er_op(c1_optokens[0], line_number);
			c11_free_tokens();
			break;
		}
		prev_tLen = c12_token_length_Er();
		op_func(&stack, line_number);
		if (c12_token_length_Er() != prev_tLen)
		{
			if (c1_optokens && c1_optokens[prev_tLen])
				c42_status_of_exit = atoi(c1_optokens[prev_tLen]);
			else
				c42_status_of_exit = EXIT_FAILURE;
			c11_free_tokens();
			break;
		}
		c11_free_tokens();
	}
	c8_free_stk(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (c31_Er_malloc());
	}

	free(line);
	return (c42_status_of_exit);
}
