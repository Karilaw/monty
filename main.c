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
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	FILE *fp;
	char *opcode;
	char *n_str;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
	{
		line_number++;
		opcode = strtok(buffer, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			n_str = strtok(NULL, " \n\t");
			push(&stack, line_number, n_str);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(fp);
	return (0);
}
