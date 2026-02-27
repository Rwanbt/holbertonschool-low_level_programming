#include "main.h"

/**
 * print_line - Prints line
 * @n: The number of print
 * @c: The number of lines
 *
 * Return: Always 0
 */
void print_line(int n)
{
	int c = 0;

	if (n > 0)
	{
		for (c = 0; c < n; c++)
		{
		_putchar('_');
		}
	}
	_putchar('\n');
}
