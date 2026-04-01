#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds node at the end
 * @head: double pointer of the head of the list
 * @n: integer to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *last;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new;
	new->prev = last;

	return (new);
}
