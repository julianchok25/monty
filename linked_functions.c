#include "monty.h"
/**
 * add_dnodeint - add a node into a doubly linked list
 * @head: Pointer to the reference of first node
 * @n: number to add into doubly linked list
 * Return: pointer with the reference to the new node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *tmp = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		tmp->prev = new;
	*head = new;
	return (*head);
}
/**
 * add_dnodeint_end - add a node at the end of the list
 * @head: pointer to the reference of the first node
 * @n: Number to add into the doubly linked list
 * Return: Pointer with the reference of the new node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = *head;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (new);
}
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

/**
 * free_vars - frees all variables into the struct global_t
 * Return: Doesn't return
 */
void free_vars(void)
{
	free_stack(vars.head);
	free(vars.buffer);
	fclose(vars.fd);
}
