#include <stdio.h>

/**
 * simple-calculator - Menu display
 */
int main(void)
{
    int enter, a, b;

    do 
    {
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
            if (enter == 1)
            {
                printf("A: ");
                scanf("%d", &a);
                printf("B: ");
                scanf("%d", &b);
                printf("Result: %d\n\n", a + b);
            }
            if (enter == 2)
            {
                printf("A: ");
                scanf("%d", &a);
                printf("B: ");
                scanf("%d", &b);
                printf("Result: %d\n\n", a - b);
            }
            if (enter == 3)
            {
                printf("A: ");
                scanf("%d", &a);
                printf("B: ");
                scanf("%d", &b);
                printf("Result: %d\n\n", a * b);
            }
            if (enter == 4)
            {
                printf("A: ");
                scanf("%d", &a);
                printf("B: ");
                scanf("%d", &b);
                if (b == 0)
                {
                    printf("Invalid division, try again.\n\n");
                }
                else
                printf("Result: %d\n\n", a / b);
            }
        }
        else
        {
            printf("Invalid choice, try again.\n\n");
        }
    }
    while (enter != 0);

    return (0);
}