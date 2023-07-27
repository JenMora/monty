#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fileDir= NULL;
	int mj_exit= EXIT_SUCCESS;

	if (argc != 2)
		return (montyRunError());

	fileDir= fopen(argv[1], "r");
	if (fileDir== NULL)
		return (fileOpenError(argv[1]));

	mj_exit= letsRunMonty(fileDir);
	fclose(fileDir);

	return (mj_exit);
}
