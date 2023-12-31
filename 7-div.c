#include "monty.h"

/**
 * div_stack - divides the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode in the file
 * Description: If the stack contains less than two elements,
 * print an error message.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}
