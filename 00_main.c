#include "monty.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char **c1_optokens = NULL;

/**
 * main - entry point
 * @argc: parameter
 * @argv: parameter
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	FILE *c2_file_dir = NULL;
	int c3_exitCd = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (c4_usage_error());
	}

	c2_file_dir = fopen(argv[1], "r");

	if (c2_file_dir == NULL)
	{
		return (c5_file_open_error(argv[1]));
	}

	c3_exitCd = c6_execute_mty(c2_file_dir);
	fclose(c2_file_dir);

	return (c3_exitCd);
}
