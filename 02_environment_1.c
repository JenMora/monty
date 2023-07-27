#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * freeTokens - frees tokens
 */

int blankLine(char *line, char *delimeter);
void freeTokens(void);
unsigned int lengthToken(void);
void (*operation_Code(char *opcode))(stack_t**, unsigned int);
int letsRunMonty(FILE *fileDir);

void freeTokens(void)
{
	size_t i = 0;

	if (token_operators == NULL)
		return;
	for (i = 0; token_operators[i]; i++)
		free(token_operators[i]);
	free(token_operators);
}

/**
 * lengthToken - checks token length
 * Return: length
 */

unsigned int lengthToken(void)
{
	unsigned int tokenLength= 0;

	while (token_operators[tokenLength])
		tokenLength++;
	return (tokenLength);
}

/**
 * monty_blankLine - is the like blank?
 * @line: the line
 * @delimeter: does it have a delimeter?
 * Return: -1 or 0
 */

int blankLine(char *line, char *delimeter)
{
	int i;
	int j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delimeter[j]; j++)
		{
			if (line[i] == delimeter[j])
				break;
		}
		if (delimeter[j] == '\0')
			return (0);
	}
	return (-1);
}

/**
 * operation_Code - checks operator
 * @opcode: the matching operator
 * Return: pointer to operator
 */

void (*operation_Code(char *opcode))(stack_t**, unsigned int)
{
	int i;
	instruction_t operationFunctions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", put_char},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", sta_ck},
		{"queue", que_ue},
		{NULL, NULL}	
	};

	for (i = 0; operationFunctions[i].opcode; i++)
	{
		if (strcmp(opcode, operationFunctions[i].opcode) == 0)
			return (operationFunctions[i].f);
	}
	return (NULL);
}

/**
 * letsRunMonty - execute
 * @fileDir: the file script to run
 * Return: Exit success or failure
 */
int letsRunMonty(FILE *fileDir)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, flee_Exit= EXIT_SUCCESS;
	unsigned int line_number = 0, previousLengthToken = 0;
	void (*operation_Function)(stack_t**, unsigned int);

	if (initStack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, fileDir) != -1)
	{
		line_number++;

		token_operators= strTow(line, DELIMETER);
		if (token_operators== NULL)
		{
			if (blankLine(line, DELIMETER))
				continue;
			mj_free_the_stack(&stack);
			return (mallocError());
		}

		else if (token_operators[0][0] == '#')
		{
			freeTokens();
			continue;
		}
		operation_Function = operation_Code(token_operators[0]);
		if (operation_Function == NULL)
		{
			mj_free_the_stack(&stack);
			flee_Exit= montyOperationError(token_operators[0], line_number);
			freeTokens();
			break;
		}
		previousLengthToken = lengthToken();
		operation_Function(&stack, line_number);
		if (lengthToken() != previousLengthToken)
		{
			if (token_operators&& token_operators[previousLengthToken])
				flee_Exit= atoi(token_operators[previousLengthToken]);
			else
				flee_Exit= EXIT_FAILURE;
			freeTokens();
			break;
		}
		freeTokens();	
	}
	mj_free_the_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (mallocError());
	}
	free(line);
	return (flee_Exit);	
}
