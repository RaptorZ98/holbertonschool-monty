#include "monty.h"

/**
 * m_add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: the line of the command
*/
void m_add(stack_t **stack, unsigned int line_number){
	stack_t *aux, *temp;
	int result;

	if (*stack != NULL){
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		if (aux->prev != NULL){
			temp = aux->prev;
			result = temp->n + aux->n;
			temp->n = result;
			temp->next = NULL;
			free(aux);
			return;
		}
	}
	fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
	_exit(EXIT_FAILURE);
}

/**
 * m_nop - does nothing
 * @stack: the stack, in this case not used
 * @line_number: the line of the command
*/
void m_nop(stack_t **stack, unsigned int line_number){
	(void)stack;
	(void)line_number;
	return;
}