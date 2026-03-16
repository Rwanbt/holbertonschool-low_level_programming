#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_name - prints a name
 * @name: name of display
 * @f: pointer of function of format display
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
