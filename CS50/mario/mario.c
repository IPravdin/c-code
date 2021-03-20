#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for hight and width
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 1 || n > 8);

    //pyramid
    int i1;
    for (int i = 1; i <= n; i++)
    {
        //dots
        i1 = (n - i);
        while (i1 > 0)
        {
            printf(" ");
            i1--;
            //printf("%i", i1);
        }

        //#
        for (int i2 = 0; i2 < i; i2++)
        {
            printf("#");
        }

        printf("  ");

        //#
        for (int i3 = 0; i3 < i; i3++)
        {
            printf("#");
        }

        printf("\n");

    }
}