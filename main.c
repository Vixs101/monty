#include "monty.h"

arg_s *arguments = NULL

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vectors
 * Return: an intepreted monty bytecode
 */
int main(int argc, char *argv[])
{
	FILE *file;

	check_arguments(argc);

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(file);

	return (0);
}
