#include <stdio.h>

/**
 * print_menu - Display menu of calculator
 *
 * Description: Display a users options
 */
void print_menu(void)
{
	printf("Simple Calculator\n");
	printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
	printf("Choice: ");
}

/**
 * main - Entry point for the calculator
 *
 * Description: Displays entry and operations
 * Return: Always 0 (Success)
 */
int main(void)
{
	int enter;
	float a, b;

	do {
		print_menu();
		if (scanf("%d", &enter) != 1)
		{
			while (getchar() != '\n')
				;
			printf("Invalid choice\n\n");
			continue;
		}

		if (enter == 0)
			printf("Bye !\n\n");
		else if (enter > 0 && enter < 5)
		{
			printf("A: ");
			scanf("%f", &a);
			printf("B: ");
			scanf("%f", &b);
			if (enter == 1)
				printf("Result: %g\n\n", a + b);
			else if (enter == 2)
				printf("Result: %g\n\n", a - b);
			else if (enter == 3)
				printf("Result: %g\n\n", a * b);
			else if (enter == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n\n");
				else
					printf("Result: %g\n\n", a / b);
			}
		}
		else
			printf("Invalid choice\n\n");
	} while (enter != 0);
	return (0);
}
