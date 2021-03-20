#include <stdio.h>

int main(void)
{
	//Decimal into Hexadecimal
	int n, i;

	printf("Enter a decimal number: ");
	scanf_s ("%i", &n);

	int remainder[10];
	for (i = 0; n > 0; i++)
	{
		remainder[i] = n % 16;
		n /= 16; //quotient

		//convert to A-F
		if (remainder[i] == 10) 
			remainder[i] = 65; //A
		else if (remainder[i] == 11) 
			remainder[i] = 66; //B
		else if (remainder[i] == 12) 
			remainder[i] = 67; //C
		else if (remainder[i] == 13) 
			remainder[i] = 68; //D
		else if (remainder[i] == 14)
			remainder[i] = 69; //E
		else if (remainder[i] == 15)
			remainder[i] = 70; //F
	}

	//show result
	for (i--; i >= 0; i--)
	{
		if (remainder[i] >= 65 && remainder[i] <= 70)
		{
			printf("%c", (char)remainder[i]);
		}
		else
		{
			printf("%d", remainder[i]);
		}
	}
}