#include "monty.h"
/**
 * stack_div - divides the second top element of stack from the top element
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_div(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) / (*head)->n;
	stack_pop(head, line_num);
}
/**
 * stack_mul - multiplies the top two elements of the stack
 * @head: head to the stack
 * @line_num: Reference to the line we are checking in case of an error
 */
void stack_mul(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int nel = 0;

	tmp = *head;
	while (tmp)
	{
		nel++;
		tmp = tmp->next;
	}
	if (nel < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n *= (*head)->n;
	stack_pop(head, line_num);
}
