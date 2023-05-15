#include "monty.h"

/**
 * m_add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: the line of the command
*/
void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *temp;
	int result;

	if (*stack != NULL)
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		if (aux->prev != NULL)
		{
			temp = aux->prev;
			result = temp->n + aux->n;
			temp->n = result;
			temp->next = NULL;
			free(aux);
			return;
		}
	}
	freeList(*stack);
	fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
	_exit(EXIT_FAILURE);
}

/**
 * m_nop - does nothing
 * @stack: the stack, in this case not used
 * @line_number: the line of the command
*/
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * prepPush - prepares the program for the funciton push
 * @token: the string with the argument for push
 * @buff: the buff to free
 * @line: the line number
 * @stack: the stack to free
 * Return: 0 if it works
*/
int prepPush(char *token, char *buff, int line, stack_t **stack)
{
	if (checkNumbers(token) == 0)
	{
		argument = atoi(token);
		free(buff);
		return (0);
	}
	free(buff);
	freeList(*stack);
	fprintf(stderr, "L<%d>: usage: push integer\n", line);
	_exit(EXIT_FAILURE);
}

/**
 * freeExit - functions made because of betty
 * @token: the string for the error message
 * @buff: the buff to free
 * @line: the line number
 * @stack: the stack to free
*/
void freeExit(char *buff, stack_t **stack, int line, char *token)
{
	fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line, token);
	free(buff);
	freeList(*stack);
	_exit(EXIT_FAILURE);
}
