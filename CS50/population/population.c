#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int initial;
    do
    {
        initial = get_int("Start size: ");
    }
    while (initial < 9);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < initial);

    // Calculate number of years until we reach threshold
    int newborn, dead, diff;
    int years = 0;

    while (end > initial)
    {
        newborn = (initial / 3);
        dead = (initial / 4);
        diff = newborn - dead;

        initial = initial + diff;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}