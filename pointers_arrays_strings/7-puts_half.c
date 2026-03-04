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
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	i = (len + 1) / 2;

	for (i = len - (len / 2); i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
