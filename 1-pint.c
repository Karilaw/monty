#include "monty.h"

/**
 * pint - prints the value on top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 * Description: If the stack is empty, print an error message.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
