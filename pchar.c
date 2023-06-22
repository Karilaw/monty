#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the script file
 *
 * Description: The integer stored at the top of the stack is treated as
 * the ASCII value of the character to be printed. If the value is not in
 * the ASCII table, print an error message and exit with EXIT_FAILURE.
 * If the stack is empty, print an error message and exit with EXIT_FAILURE.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

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
