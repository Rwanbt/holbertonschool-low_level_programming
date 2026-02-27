#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers, from 0 to 14, followed by a new line
 */
void more_numbers(void)
{
	int colone;
	int line = 1;

	while (line <= 10)
	{
		for (colone = 0; colone <= 14; colone++)
		{
			if (colone > 9)
			{
				_putchar((colone / 10) + '0');
			}
			_putchar((colone % 10) + '0');
		}
		_putchar('\n');
		line++;	
	}
}
