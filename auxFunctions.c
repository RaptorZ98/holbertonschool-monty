#include "monty.h"

/**
 * freeList - free a linked list
 * @stack: the list to free
*/
void freeList(stack_t *stack)
{
	if (stack != NULL)
	{
		if (stack->next != NULL)
			freeList(stack->next);
		free(stack);
	}
}

/**
 * _getCommand - open and reads the file looking for the commands
 * @file: the file to read
 * @stack: the stack to pass to the op functions
*/
void _getCommand(char *file, stack_t **stack)
{
	int line = 0, pos = 0;
	char *buff = NULL;
	size_t n = 0;
	FILE *filed;

	filed = fopen(file, "r");
	if (filed == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		_exit(EXIT_FAILURE);
	}

	while (getline(&buff, &n, filed) != -1)
	{
		line++;
		while (buff[pos] && buff[pos] <= 32)
			pos++;
		if (!buff[pos])
		{
			free(buff);
			buff = createBuff();
			continue;
		}
		checkCommand(buff, line, stack);
		buff = createBuff();
	}
	free(buff);
	freeList(*stack);
	fclose(filed);
}

/**
 * checkCommand - check if the command exists and executes it
 * @buff: the string with the command and arguments
 * @line: the line number
 * @stack: the stack to pass to the function
*/
void checkCommand(char *buff, int line, stack_t **stack)
{
	instruction_t op[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pop", m_pop},
		{"pint", m_pint},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{NULL, NULL}
	};
	char *token = buff;
	int i = 0;

	token = strtok(buff, " \n\t$");
	while (op[i].f != NULL)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			if (strcmp(token, "push") != 0)
			{
				free(buff);
				op[i].f(stack, line);
				break;
			}
			else
			{
				token = strtok(NULL, " \n\t$");
				if (prepPush(token, buff, line, stack) == 0)
				{
					op[i].f(stack, line);
					break;
				}
			}
		}
		i++;
	}
	if (op[i].opcode == NULL)
	{
		freeExit(buff, stack, line, token);
	}
}

/**
 * checkNumbers - checks if the string is only numbers
 * @token: the string to check
 * Return: 0 if only numbers, 1 if there is another char
*/
int checkNumbers(char *token)
{
	int n = 0;

	if (token == NULL)
		return (1);
	while (token[n] != '\0')
	{
		if (n == 0 && token[n] == '-')
			n++;
		else if (token[n] >= '0' && token[n] <= '9')
			n++;
		else
			return (1);
	}
	return (0);
}

/**
 * createBuff - creates a null string
 * Return: the null string
*/
char *createBuff(void)
{
	char *buff = NULL;

	return (buff);
}
