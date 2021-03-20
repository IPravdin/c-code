#include <stdio.h>

int main()
{
	int integer[10];
	//get integer[10]
	for (int i = 0; i < 10; i++)
	{
		printf("%i: ", i+1);
		scanf_s("%i", &(integer[i]));
	}

	//calculations
	int ii = 0;
	int sum = 0;
	for (; ii < 10; ii++)
	{
		sum += integer[ii];
	}
	double mean = (double) sum / ii;
	printf("Mean %i / %i: %f", sum, ii, mean);
	
}
