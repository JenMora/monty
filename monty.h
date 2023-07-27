#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MJ_STACK 0
#define MJ_QUEUE 1
#define DELIMETER " \n\t\a\b\r"

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
} stack_t;
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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern char **token_operators;

void mj_free_the_stack(stack_t **stack);
int initStack(stack_t **stack);
int checkMonty(stack_t *stack);
void freeTokens(void);
unsigned int lengthToken(void);
int letsRunMonty(FILE *fileDir);
void setOprationTokenError(int _mj_err);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void put_char(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void sta_ck(stack_t **stack, unsigned int line_number);
void que_ue(stack_t **stack, unsigned int line_number);


int montyRunError(void);
int mallocError(void);
int fileOpenError(char *filename);
int montyOperationError(char *opcode, unsigned int line_number);
int noInternalError(unsigned int line_number);
int popError(unsigned int line_number);
int pintError(unsigned int line_number);
int stackError(unsigned int line_number, char *operat);
int division_error(unsigned int line_number);
int putcharError(unsigned int line_number, char *msg);


char **strTow(char *str, char *delimeter);
char *getInteger(int n);

int is_delim(char ch, char *delimeter);
int get_word_length(char *str, char *delimeter);
int get_word_count(char *str, char *delimeter);
char *wordNext(char *str, char *delimeter);
int countWords(char *str, char *delimeter);
int lenWords(char *str, char *delimeter);


#endif /* __MONTY_H__ */

