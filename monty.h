#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

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

/**
 * struct arg_s - hold variables
 * @file: file that connects to the stream from file
 * @line: string which will be the line of text read from file
 *
 * Description: holdvariables that will be used in different functions
 * of the project as well as variables that will require
 * memory allocation and freeing
 */
typedef struct arg_s
{
	FILE *file;
	char *line;
} arg_s;

extern arg_s *arguments;

/* functions that satisfies the first checks */
void check_arguments(int argc);
void initialize_args(void);
void malloc_failed(void);
void free_arguments(void);

#endif /*MONTY_H*/
