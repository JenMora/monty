#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "monty.h"

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

int main(int argc, char **argv)
{
    FILE *bytecode;
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    ssize_t line_size;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    bytecode = fopen(argv[1], "r");
    if (!bytecode)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line_buf, line_buf_size, bytecode))
    {
        line_size = strlen(line_buf);
        if (line_size > 1)
        {
            execute_line(line_buf, &stack, line_number);
        }
    }
    free(line_buf);
    fclose(bytecode);
    free_stack(&stack);
    return 0;
}

