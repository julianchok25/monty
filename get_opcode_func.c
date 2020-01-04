#include "monty.h"

/**
 * get_opcode_func - get the option of char input to perform the opcode
 * @s: input opcode
 * Return: a pointer to the function given the opcode or NULL if not found
 */
void (*get_opcode_func(char *s))(stack_t, unsigned int)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{NULL, NULL}
	};

	while (stack[i].opcode != '\0')
	{
		if (*s == *(stack[i]).opcode)
			return (*(stack[i]).f);
		i += 1;
	}
	return (NULL);
}
