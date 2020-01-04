#include "monty.h"

static global_t vars;

/**
 * free_vars - frees all variables into the struct global_t
 * Return: Doesn't return
 */
free_vars()
{
	free_stack(vars.head);
	free(vars.buffer);
	fclose(vars.fd);
}
/**
 * init - initialize all variables into the struct global_t
 * @fd: - file descriptor of file opened
 * Return: No return
 */
void init(FILE *fd)
{
	order = 1;
	vars.fd = fd;
	vars.cline = 1;
	vars.buffer = NULL;
	vars.stack = 1;
}
/**
 * main - this function evaluates the input to execute the
 * functions
 * @argc: Counter of arguments
 * @argv: Pointer to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	File *fd;
	size_t size = 128;
	ssize_t line_num = 0;
	char *args[2] = {NULL, NULL};
	void (*f)(stack_t, unsigned int);

	fd = check_open(argc, argv);
	init(fd);
	line_num = getline(&buffer, &size, fd);
	while (line_num != -1)
	{
		args[0] = strtok(vars.buffer, " \n\t");
		if (args[0][0] != '#' && args[0] != NULL)
		{
			f = get_opcode_func(args[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vars.cline);
				dprintf(2, "unknown instruction %s\n", args[0]);
				free_vars();
				exit(EXIT_FAILURE);
			}
			vars.stack = strtok(NULL, " \n\t");
			f(&vars.head, vars.cline);
		}
		line_num = getline(&vars.buffer, &size, fd);
		vars.cline++;
	}

	free_vars();
	return (0);
}
