#include <stdio.h>

/**
 * simple-calculator - Menu display
 */
int main(void)
{
    int e;

    do 
    {
        printf("Simple Calculator\n");
        printf("1) Add\n 2) Subtract\n 3) Multiply\n 4) Divide\n 0) Quit\n");
        printf("Choice: ");
        scanf("%d", &e);
    
        if (e == 0)
        {
            printf("Bye !\n");
        }
        else if (e > 0 && e < 5)
        {
            printf("Opérations: %d\n", e);
        }
        else
        {
            printf("Invalid choice, try again. \n");
        }
    }
    while (e != 0);

    return (0);
}