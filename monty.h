#ifndef MONTY_H
#define MONTY_H

/* ---STANDARD C  LIBRARIES FOR THIS PROJECT --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int global_count;
int error_signal;
char **args;


/* ---DATA STRUCTURES USED IN MONTY--- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} mj_stack;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(mj_stack **stack, unsigned int mj_count);
} instruction_t;
/* ---GLOBAL VARIABLES USED IN MONTY--- */
#define TOKEN_DELIMITER " \t\r\n\a"


/* ---PROTOTYPES FOR MONTY FUNCTIONS--- */
void interpreter(char *argv[]);
char **split_line(char *line);
void (*get_function(char *command))(mj_stack **, unsigned int);
int execute_args(char **args);
void push(mj_stack **stack, unsigned int mj_count);
void pall(mj_stack **stack, unsigned int mj_count);
void free_stack(mj_stack **stack);
void pint(mj_stack **stack, unsigned int mj_count);
void pop(mj_stack **stack, unsigned int mj_count);
void swap(mj_stack **stack, unsigned int mj_count);
void add(mj_stack **stack, unsigned int mj_count);
void nop(mj_stack **stack, unsigned int mj_count);
void sub(mj_stack **stack, unsigned int mj_count);
void _div(mj_stack **stack, unsigned int mj_count);
void _mul(mj_stack **stack, unsigned int mj_count);
void _mod(mj_stack **stack, unsigned int mj_count);
void pchar(mj_stack **stack, unsigned int mj_count);
void pstr(mj_stack **stack, unsigned int mj_count);
void rotl(mj_stack **stack, unsigned int mj_count);
void rotr(mj_stack **stack, unsigned int mj_count);

static const instruction_t commands_hashmap[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", _div},
	{"mul", _mul},
	{"mod", _mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL}
};

#endif

