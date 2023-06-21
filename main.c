#include "monty.h"

/**
 * main - entry point for monty interpreter
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Description: Reads opcodes from a file and executes them.
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = open_file(argv[1]);
	process_opcodes(fp, &stack);

	fclose(fp);
	return (0);
}
