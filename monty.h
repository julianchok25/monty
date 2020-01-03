#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

/**
 * struct global_variables - all global variables to initialize
 * @fd: File wil be open
 * @cline: Counter of lines into file
 * @buffer: this pointer allocate the data of each line of the file
 * @stack: Reference to the stack will be added
 *
 * Description: keeps all variables expecting for a value
 */
typedef struct global_variables
{
	File *fd;
	int cline;
	char *buffer;
	int stack;
} global_t;
void (*get_opcode_func(char *s))(stack_t **stack, unsigned int line_number);
#endif /* #ifndef MONTY_H */
