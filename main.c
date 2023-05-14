#include "monty.h"

/**
 * main - the Monty byteCodes files interpreter
 * @argc: the number of arguments passed to the function
 * @argv: the arguments passed
 * Return: 0 if fucntions correctly
*/
int main(int argc, char **argv){
	char *buff;
	FILE *file;

	if (argc != 2){
		fprintf(stderr, "USAGE: monty file\n");
		_exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL){
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		_exit(EXIT_FAILURE);
	}
	buff = _getCommand(file);

	fclose(file);
	return 0;
}