#include "monty.h"

/**
 * initialize_args - initializes the pointer
 * to the arg_s structure
 */

void initialize_args(void)
{
	arguments = malloc(sizeof(arg_s));
	if (arguments == NULL)
		malloc_failed();

	arguments->file = NULL;
	arguments->line = NULL;
}

/**
 * get_file - gets the stream for reading from the specified file.
 * @fileName:name of the file to open and set as the stream
 */

void get_file(char *fileName)
{
	FILE *file;

	file = fopen(fileName, "r");
	if (file == NULL)
	{
		get_file_failed(fileName);
	}

	arguments->file = file;
}
