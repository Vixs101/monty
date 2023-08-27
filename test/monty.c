#include "monty.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, char **argv)
{
    FILE *fd;
    char *filename;
    int line_num = 0;
    size_t len = 0;
    char *line = NULL, *token = NULL, *tok_value;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    fd = fopen(filename, "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, fd) != -1)
    {
        line_num++;
        token = strtok(line, " \n\t\r");
        if (token == NULL || strlen(token) == 0)
        {
            free(token);
            printf("Empty\n");
            break;
        }
        if (strcmp(token, "push") == 0)
        {
            tok_value = strtok(NULL, " \n\t\r");
            
        }
        else
        {
            get_opcode(&stack, token, line_num);
        }
        printf("L%d, %s\n",line_num, tok_value);
    }
    printf("1%s\n",line);
    free(line);
    printf("2%s\n", line);
    fclose(fd);
    return (0);
}
