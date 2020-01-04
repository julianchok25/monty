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

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vars();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = (*head);
	new->prev = NULL;
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
	stack_t *new, *tmp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vars();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->next = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	return (tmp->next);
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
