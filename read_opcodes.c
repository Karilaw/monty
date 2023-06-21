#include "monty.h"

/**
 * process_opcodes - processes opcodes from file
 * @fp: pointer to opened file
 * @stack: double pointer to top of stack
 */
void process_opcodes(FILE *fp, stack_t **stack)
{
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	char *opcode;
	char *n_str;

	while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
	{
		line_number++;
		opcode = strtok(buffer, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			n_str = strtok(NULL, " \n\t");
			push(stack, line_number, n_str);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
