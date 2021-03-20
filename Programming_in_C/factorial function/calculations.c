#include <stdio.h>

int factorial(float n) 
{
	int contr_n = (int) (n * 10) % 10;

	// if decimal number is sufficient to be rounded
	if (contr_n >= 5)
	{
		n = n + 1;
		printf("As entered number had a decimal, it's rounded into: %i!.\n", (int) n);
	}

	// if decimal is not sufficient to be rounded
	else if (contr_n < 5)
	{
		printf("As entered number had a decimal, it's rounded into: %i!.\n", (int)n);
	}

	int sum = 1;
	int int_n = (int) n;
	for (; int_n > 0; int_n--)
	{
		sum = sum * int_n;
	}
	return sum;
}

