#include "lists.h"

/**
 * list_len - Number of elements in the list
 * @h: Pointer of the head of list
 *
 * Return: the Number of node
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
