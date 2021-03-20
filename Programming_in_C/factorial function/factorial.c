#include <stdio.h>
#include "calculations.h"

int main()
{
	float n;
	printf("Enter integer: ");
	scanf_s("%f", &n);

	printf("%i", factorial(n));
}
