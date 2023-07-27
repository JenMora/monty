#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "monty.h"

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

int main(void)
{
	FILE *mj_byt_code = fopen("path/to/your/file", "r");
	char buf_at_line[512];
	unsigned int ln_num = 0;
	stack_t *stack = NULL;
	size_t size_of_line;

	if (mj_byt_code == NULL)
	{
		fprintf(stderr, "Error: Cannot open file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buf_at_line, sizeof(buf_at_line), mj_byt_code))
	{
		size_of_line = strlen(buf_at_line);
		if (size_of_line > 1)
		{
			execute_line(buf_at_line, &stack, ln_num);
		}
		ln_num++;
	}

	fclose(mj_byt_code);
	free_stack(&stack);

	return (0);

	/*FILE *mj_byt_code;
	char *buf_at_line = NULL;
	unsigned int ln_num = 0;
	size_t buf_at_size_of_line = 0;
	ssize_t size_of_line;
	stack_t *stack = NULL;
	

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buf_at_line, buf_at_size_of_line, mj_byt_code))
	{
		size_of_line = strlen(buf_at_line);

		if (size_of_line > 1)
		{
			execute_line(buf_at_line, &stack, ln_num);
		}
	}
	free(buf_at_line);
	fclose(mj_byt_code);
	free_stack(&stack);
	return (0);*/
}
