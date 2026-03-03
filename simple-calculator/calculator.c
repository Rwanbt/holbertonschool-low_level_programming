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
            printf("Bye !\n");
        }
        else if (enter > 0 && enter < 5)
        {
            printf("Opérations: %d\n", enter);
            if (enter == 1)
            {
                scanf("%d", &a);
                scanf("%d", &b);
                printf("result: %d\n", a + b);
            }
        }
        else
        {
            printf("Invalid choice, try again. \n");
        }
    }
    while (enter != 0);

    return (0);
}