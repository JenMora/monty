#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    opcode = strtok(line, " \n\t");

    if (!opcode)
    {
        fprintf(stderr, "Error: No opcode found on line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

