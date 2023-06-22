#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the script file
 * Description: If the stack is empty, print an error message.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}
