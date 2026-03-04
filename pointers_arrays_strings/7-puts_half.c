#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: the string to treated
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i;
	int len;
	int start;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
		start = len - (len / 2);
	}
	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
