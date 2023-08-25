#include "monty.h"

/**
 * check_arguments - checks the number of command line args
 * @argc: argument count
 */

void check_arguments(int argc)
{
	if (argc == 2)
		return;

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_failed - handles the error when malloc fails to allocate memory
 */

void malloc_failed(void)
{
	fprintf(stderr, "malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * free_arguments - frees the arguments if malloc fails
 */
void free_arguments(void)
{
	free(arguments->file);
	free(arguments->line);

	free(arguments);
}

/**
 * get_file_failed - Handles the error when reading a file fails
 * @fileName: the nae of the file that fail to open
 */

void get_file_failed(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_arguments();
	exit(EXIT_FAILURE);
}
