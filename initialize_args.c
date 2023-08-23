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
