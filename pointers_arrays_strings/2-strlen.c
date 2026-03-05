#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to check
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int count;

	while (s[count] != '\0')
	{
		count++;
	}

	return (count);
}
