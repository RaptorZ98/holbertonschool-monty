#include "monty.h"

/**
 * m_push - pushes an element to the stack
 * @stack: the stack to add the elements to
 * @line_number: the line number of the command
*/
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *aux;

	(void)line_number;
	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		freeList(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		_exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
	}
	else
		*stack = new;
	new->next = NULL;
	new->n = argument;
}

/**
 * m_pall - prints all the values on the stack, starting from the top
 * @stack: the stack to print
 * @line_number: the line number of the command
*/
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	(void)line_number;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
 * m_pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: the line number of the command
*/
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *temp;

	if (*stack == NULL)
	{
		freeList(*stack);
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		_exit(EXIT_FAILURE);
	}
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	if (aux->prev != NULL)
	{
		temp = aux->prev;
		temp->next = NULL;
	}
	free(aux);
}
/**
 * m_pint - prits the value at the top of the stack
 * @stack: the stack
 * @line_number: the line of the command
*/
void m_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (*stack == NULL)
	{
		freeList(*stack);
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		_exit(EXIT_FAILURE);
	}
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	printf("%d\n", aux->n);
}
/**
 * m_swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line of the command
*/
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *temp;
	int tempNum;

	if (*stack != NULL)
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		if (aux->prev != NULL)
		{
			temp = aux->prev;
			tempNum = aux->n;
			aux->n = temp->n;
			temp->n = tempNum;
			return;
		}
	}
	freeList(*stack);
	fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
	_exit(EXIT_FAILURE);
}
