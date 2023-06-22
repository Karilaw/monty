#include "monty.h"

/**
 * is_comment - checks if a line is a comment
 * @line: line to check
 *
 * Return: 1 if the line is a comment, 0 otherwise
 */
int is_comment(char *line)
{
	while (*line)
	{
		if (*line == '#')
			return (1);
		if (!isspace(*line))
			return (0);
		line++;
	}
	return (0);
}
