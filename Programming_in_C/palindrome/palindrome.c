#include <stdio.h>
#define N 7

int main()
{
	int i, j, product, working_product;
	int component[N];
	// first multiplier
	for (i = 1; i < 1000; i++)
	{
		// second multiplier
		for (j = 1; j < 1000; j++)
		{
			product = i * j;
			working_product = product;
			// product separated into independent ints and stored in array
			for (int a = 0; a < N; a++)
			{
				component[a] = working_product % 10;
				working_product /= 10;

			}
			// checks whether number is palindromic or not and higher 900000 (to narrow the search)
			if (component[0] == component[5] && component[1] == component[4] && component[2] == component[3] && component[0] != 0 && product >= 900000)
			{
				printf(" %d ", product);
			}
		}
	}
}
