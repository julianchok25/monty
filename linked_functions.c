#include "monty.h"
/**
 * free_stack - free a doubly linked list
 * @head: Pointer to the first node of doubly linked list
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
}
