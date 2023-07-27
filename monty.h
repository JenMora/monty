#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b\r"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/****** GLOBAL OPCODE TOKEN *****/
extern char **op_toks;

/****** INTERPRETER FUNCTION PROTOTYPES *******/
void monty_free_stack(stack_t **stack);
int monty_monty_init_stack(stack_t **stack);
int monty_check_mode(stack_t *stack);
void monty_free_tkns(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/****** OPCODE FUNCTION PROTOTYPES*******/
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/**********ERROR msgS & ERROR CODES ******/
int monty_usg_err(void);
int monty_malloc_err(void);
int f_open_error(char *filename);
int monty_op_err(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int monty_pop_err(unsigned int line_number);
int monty_pint_err(unsigned int line_number);
int monty_stack_err(unsigned int line_number, char *op);
int monty_div_err(unsigned int line_number);
int pchar_error(unsigned int line_number, char *msg);

/******CUSTOM  C STANDARD LIBRARY FUNCTIONS *****/
char **strtow(char *str, char *delims);
char *get_int(int n);


#endif /* __MONTY_H__ */

