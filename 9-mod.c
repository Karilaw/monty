#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = mod;
}
