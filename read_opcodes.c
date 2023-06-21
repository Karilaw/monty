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
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub(stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			div_stack(stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul_stack(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
