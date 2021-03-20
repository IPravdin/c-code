#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n0;
    do
    {
        n0 = get_float("Change owed: ");
    }
    while (n0 < 0);
    
    int n1 = round(n0 * 100);
    int x = 0;
    
    while (n1 > 0)
    {
        if (n1 >= 25)
        {
            n1 = n1 - 25;
            x++;
        }
        else if (n1 < 25 && n1 >= 10)
        {
            n1 = n1 - 10;
            x++;
        }
        else if (n1 < 10 && n1 >= 5)
        {
            n1 = n1 - 5;
            x++;
        }
        else if (n1 < 5 && n1 >= 1)
        {
            n1 = n1 - 1;
            x++;
        }
    }
    printf("%i\n", x);
}