#include <stdio.h>
#include "lists.h"

/**
 * dlistint_len - Return the number of elements in a liked
 * @h: pointer of the head of the list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
