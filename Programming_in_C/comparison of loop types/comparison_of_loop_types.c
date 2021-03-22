#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int whilef(void);
int do_whilef(void);
int forf(void);

int main(void)
{
	//Comparison of while, do .. while, and for loops
	whilef();
	do_whilef();
	forf();
	
	return 0;
}

int whilef(void)
{
	printf("WHILE LOOP\n");

	printf("1st test:\n");
	int i = 0;
	while (i <= 100)
	{
		printf("%4i", i);
		i++;
	}

	printf("\n2nd test:\n");
	int n = 0;
	printf("enter positive number: ");
	scanf_s("%i", &n);

	//test whether positive or negative
	while (n <= 0)
	{
		printf("please enter positive number: ");
		scanf_s("%i", &n);
	}

	while (n > 0)
	{
		printf("*");
		n--;
	}
	printf("\n");

	printf("3rd test:\n");
	char c;
	int test = 0;

	printf("enter 'q' or 'Q': ");
	scanf("%c", &c);
	while (c != 'q' && c != 'Q')
	{
		printf("enter 'q' or 'Q': ");
		scanf("%c", &c);
	}
}

int do_whilef(void)
{
	printf("\nDO WHILE LOOP\n");
	printf("1st test:\n");
	int i = 0;
	do
	{
		printf("%4i", i);
		i++;
	} 	while (i <= 100);

	printf("\n2nd test:\n");
	// get number of *
	int n;
	do
	{
		printf("enter positive number: ");
		scanf("%i", &n);
	} 	while (n < 0);

	//print *
	do
	{
		printf("*");
		n--;
	} 	while (n > 0);

	printf("\n3rd test:\n");
	char c;
	do
	{
		printf("enter 'q' or 'Q': ");
		scanf("%c", &c);
	} while (c != 'q' && c != 'Q');
}

int forf(void)
{
	printf("\nFOR LOOP\n");
	printf("1st test:\n");
	for (int i = 0; i <= 100; i++)
	{
		printf("%4i", i);
	}

	printf("2nd test:\n");
	int n = 0;
	for (; n < 1; )
	{
		printf("enter positive number: ");
		scanf("%i", &n);
	}

	for (; n > 0; n--)
	{
		printf("*");
	}

	printf("\n3rd test:\n");
	char c = '0';
	for (; c != 'q' && c != 'Q'; )
	{
		printf("enter 'q' or 'Q': ");
		scanf("%c", &c);
	}
}