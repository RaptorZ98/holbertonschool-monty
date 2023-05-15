#include "monty.h"

/**
 * main - the Monty byteCodes files interpreter
 * @argc: the number of arguments passed to the function
 * @argv: the arguments passed
 * Return: 0 if fucntions correctly
*/
int main(int argc, char **argv)
{
	stack_t *nod = NULL;
	stack_t **stack = &nod;

	argument = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		_exit(EXIT_FAILURE);
	}

	_getCommand(argv[1], stack);

	return (0);
}
