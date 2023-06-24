#include "monty.h"
/**
 * free_stack - frees the memory
 * @stack: pointer to the pointer of head of stack
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}

}
