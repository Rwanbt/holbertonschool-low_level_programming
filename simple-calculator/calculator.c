#include <stdio.h>

/**
 * main - Entry point for the calculator
 *
 * Description: Displays menu and operations
 * Return: Always 0 (Success)
 */
int main(void)
{
	int enter, a, b;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: ");
		scanf("%d", &enter);

		if (enter == 0)
		{
			printf("Bye !\n\n");
		}
		else if (enter > 0 && enter < 5)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);

			if (enter == 1)
				printf("Result: %d\n\n", a + b);
			else if (enter == 2)
				printf("Result: %d\n\n", a - b);
			else if (enter == 3)
				printf("Result: %d\n\n", a * b);
			else if (enter == 4)
			{
				if (b == 0)
					printf("Error: division by zero\n\n");
				else
					printf("Result: %d\n\n", a / b);
			}
		}
		else
			printf("Invalid choice, try again.\n\n");
	} while (enter != 0);
	return (0);
}
