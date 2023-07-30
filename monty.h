#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1
#define C7_DELIMITER " \n\t\a\b\r"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **c1_optokens;

void c8_free_stk(stack_t **stack);
int c9_init(stack_t **stack);
int c10_check(stack_t *stack);
void c11_free_tokens(void);
unsigned int c12_token_length_Er(void);
int c6_execute_mty(FILE *c2_file_dir);
void c13_token_opSet_Er(int error_code);

void c14_op_push(stack_t **stack, unsigned int line_number);
void c15_op_pall(stack_t **stack, unsigned int line_number);
void c16_op_pint(stack_t **stack, unsigned int line_number);
void c17_op_pop(stack_t **stack, unsigned int line_number);
void c18_op_swap(stack_t **stack, unsigned int line_number);
void c19_op_add(stack_t **stack, unsigned int line_number);
void c21_op_nop(stack_t **stack, unsigned int line_number);
void c20_op_sub(stack_t **stack, unsigned int line_number);
void c22_op_div(stack_t **stack, unsigned int line_number);
void c23_op_mul(stack_t **stack, unsigned int line_number);
void c24_op_mod(stack_t **stack, unsigned int line_number);
void c25_op_putchar(stack_t **stack, unsigned int line_number);
void c26_op_pstr(stack_t **stack, unsigned int line_number);
void c27_op_rotl(stack_t **stack, unsigned int line_number);
void c28_op_rotr(stack_t **stack, unsigned int line_number);
void c29_op_stack(stack_t **stack, unsigned int line_number);
void c30_op_queue(stack_t **stack, unsigned int line_number);


int c4_usage_error(void);
int c31_Er_malloc(void);
int c5_file_open_error(char *filename);
int c31_Er_op(char *opcode, unsigned int line_number);
int c32_Er_NoInteger(unsigned int line_number);
int c17_op_pop_err(unsigned int line_number);
int c16_op_pint_err(unsigned int line_number);
int c29_op_stack_err(unsigned int line_number, char *op);
int c22_op_div_err(unsigned int line_number);
int c32_Er_putchar(unsigned int line_number, char *msg);

char **c33_str_tow(char *str, char *c7_delimiter);
char *c34_get_integer(int n);

int is_delim(char ch, char *c7_delimiter);
int c43_word_length(char *str, char *c7_delimiter);
int c44_word_count(char *str, char *c7_delimiter);
char *c45_word_next(char *str, char *c7_delimiter);

#endif /* MONTY_H */

