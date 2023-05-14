#include "monty.h"

/**
 * freeList - free a linked list
 * stack - the list to free
*/
void freeList(stack_t *stack){
	if (stack != NULL){
		if (stack->next != NULL)
			freeList(stack->next);
		free(stack);
	}
}

char * _getCommand(FILE *file){
	int line = 0;
	char *buff;
	size_t n = 0;

	while (getline(&buff, &n, file) != -1){
		checkCommand(buff);
	}
}

int checkCommand(char *buff){
	instruction_t op = {
		{"push", m_push},
		{"pall", m_pall},
		{"pop", m_pop},
		{"pint", m_pint},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop}
	};
	char *token;

	token = strtok(buff, " \n\t$");
	
}