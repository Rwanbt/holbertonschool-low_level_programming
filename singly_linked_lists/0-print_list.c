#include <stdio.h>
#include "lists.h"

/**
 * print_list - Display all elements of list_t.
 * @h: Pointer to head of list.
 *
 * Return: The number of node.
*/
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		count++;
	}

	return (count);
}
