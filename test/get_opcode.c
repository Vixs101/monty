#include "monty.h"

int get_opcode(stack_t **stack, char *token, int line_number)
{
    unsigned int i = 0;
    instruction_t op[] = {
        {"pall", pall}, {"pop", pop},
        {"pint", pint}, {NULL, NULL}
    };

    while(op[i].opcode != NULL)
    {
        if (strcmp(token, op[i].opcode) == 0)
        {
            (op[i].f)(stack, line_number);
            return (EXIT_SUCCESS);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        i++;
    }


}