#include "monty.h"

void execute_line(char *line, stack_t **stack, unsigned int ln_num)
{
	char *mj_operation_code;
	mj_operation_code = strtok(line, " \n\t");

	if (!mj_operation_code)
	{
		fprintf(stderr, "Error: No mj_operation_code found on line %u\n", ln_num);
		exit(EXIT_FAILURE);
	}

	if (strcmp(mj_operation_code, "push") == 0)
	{
		push(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_pall") == 0)
	{
		mj_pall(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_pint") == 0)
	{
		mj_pint(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_pop") == 0)
	{
		mj_pop(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_swap") == 0)
	{
		mj_swap(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_add") == 0)
	{
		mj_add(stack, ln_num);
	}

	else if (strcmp(mj_operation_code, "mj_nop") == 0)
	{
		mj_nop(stack, ln_num);
	}

	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", ln_num, mj_operation_code);
		exit(EXIT_FAILURE);
	}
}
