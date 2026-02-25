#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int ligne, colone, nombre;

	for (ligne = 0; ligne <= 9; ligne++)
	{
		for (colone = 0; colone <= 9; colone++)
		{
			nombre = ligne * colone;

			if (colone == 0)
			{
				_putchar(nombre + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				if (nombre < 10)
				{
					_putchar(' ');
					_putchar(nombre + '0');
				}
				else
				{
					_putchar((nombre / 10) + '0');
					_putchar((nombre % 10) + '0');
				}
			}
		}
		_putchar('\n');
	}
}