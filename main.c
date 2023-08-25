#include "monty.h"

arg_s *arguments = NULL;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vectors
 * Return: an intepreted monty bytecode
 */
int main(int argc, char *argv[])
{
	size_t n = 0;

	check_arguments(argc);
	initialize_args();
	get_file(argv[1]);

	while (custom_getline(&arguments->line, &n, arguments->file) != -1)
	{
		printf("%s\n", arguments->line);
	}
	return (0);
}
