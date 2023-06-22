#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the script file
 * Description: The string stops when either:the stack is over
 * the value of the element is 0
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int c;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		c = temp->n;
		if (c <= 0 || c > 127)
			break;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}
