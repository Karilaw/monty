#include "monty.h"

/**
 * open_file - opens and validates file
 * @filename: name of file to open
 * Return: pointer to opened file
 */
FILE *open_file(char *filename)
{
	FILE *fp;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
