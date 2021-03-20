#include <stdio.h>

int main(void)
{
    int x;
    do
    {
        printf("Enter intenger: ");
        scanf_s("%i", &x);
    } 
    while ((x * 10) % 10 != 0);

    // even or odd
    if (x % 2 == 0)
        printf("Number iss Even\n");
    else
        printf("Number is Odd\n");

    // devisible by 3
    if (x % 3 == 0)
        printf("Number is devisible by 3\n");
    else 
        printf("Number is not devisible by 3\n");

    // number positive or negative or zero
    if (x > 0)
        printf("Number is positive\n");
    else if (x < 0)
        printf("Number is negative\n");
    else
        printf("It's zero\n");
    
    // if add 1, is it devisible by 7
    x++;
    if (x % 7 == 0)
        printf("Number %i + 1 is devisible by 7\n", --x);
    else
        printf("Number %i + 1 is not devisible by 7\n", --x);
}