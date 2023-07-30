#include "monty.h"

/**
 * c13_token_opSet_Er - error
 * @error_code: integer
 * Return: Exit failure
 */
void c13_token_opSet_Er(int error_code)
{
	int len_of_tok = 0, i = 0;
	char *exit_str = NULL;
	char **tok_new = NULL;

	len_of_tok = c12_token_length_Er();
	tok_new = malloc(sizeof(char *) * (len_of_tok + 2));
	if (c1_optokens == NULL)
	{
		c31_Er_malloc();
		return;
	}
	while (i < len_of_tok)
	{
		tok_new[i] = c1_optokens[i];
		i++;
	}
	exit_str = c34_get_integer(error_code);
	if (exit_str == NULL)
	{
		free(tok_new);
		c31_Er_malloc();
		return;
	}
	tok_new[i++] = exit_str;
	tok_new[i] = NULL;
	free(c1_optokens);
	c1_optokens = tok_new;
}
