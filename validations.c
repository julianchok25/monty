#include "monty.h"
/**
 * init - initialize all variables into the struct global_t
 * and keep values while the program finish
 * @fd: - file descriptor of file opened
 * Return: No return
 */
void init(FILE *fd)
{
	vars.fd = fd;
	vars.cline = 1;
	vars.buffer = NULL;
	vars.stack = NULL;
}
/**
 * check_open - validate if the argument represent a file or not
 * @argc: Counter of arguments
 * @argv: Pointer with the reference to arguments
 * Return: File descriptor of file opened or -1 is not exists
 */
FILE *check_open(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
