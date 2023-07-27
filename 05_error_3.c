#include "monty.h"

/**
 * setOprationTokenError - error
 * @_mj_err: integer
 * Return: Exit failure
 */
void setOprationTokenError(int _mj_err)
{
	int tokenLength= 0, i = 0;
	char *exit_string = NULL;
	char **tokenNew = NULL;

	tokenLength= lengthToken();
	tokenNew = malloc(sizeof(char *) * (tokenLength+ 2));

	if (!token_operators)
	{
		mallocError();
		return;
	}

	while (i < tokenLength)
	{
		tokenNew[i] = token_operators[i];
		i++;
	}
	exit_string = getInteger(_mj_err);
	if (!exit_string)
	{
		free(tokenNew);
		mallocError();
		return;
	}
	tokenNew[i++] = exit_string;
	tokenNew[i] = NULL;
	free(token_operators);
	token_operators= tokenNew;
}
