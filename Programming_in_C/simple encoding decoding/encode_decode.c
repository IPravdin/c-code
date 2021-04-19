#include <stdio.h>

void encoding(char* string, int sizeOfString);
void decoding(char* string, int sizeOfString);

int main()
{
	char pstr[30];

	//get string
	int i;
	for (i = 0; i < 30 - 1; i++)
	{
		pstr[i] = getchar();
		if (pstr[i] == '\n' || pstr[i] == '\r')
		{
			i++;
			break;
		}
	}
	pstr[i] = '\0';

	//encode string
	encoding(pstr, sizeof(pstr));
	printf("%s", pstr);

	//decode string
	decoding(pstr, sizeof(pstr));
	printf("%s", pstr);
}

void encoding(char* string, int sizeOfString)
{
	int i;
	for (i = 0; i < sizeOfString - 1; i++)
	{
		//if lowercase
		if (string[i] >= 'a' && string[i] <= 'z')
		{
			string[i] += 'A' - 'a';
		}

		//encode 'A'-'J' to '0'-'9'
		if (string[i] >= 'A' && string[i] <= 'J')
		{
			string[i] = string[i] - ('A' - '0');
		}

		//encode 'K'-'R' to 'Z'-'S'
		if (string[i] >= 'K' && string[i] <= 'R')
		{
			string[i] = ('R' - string[i]) + 'S';
		}
		//encode 'Z'-'S' to 'K'-'R'
		else if (string[i] >= 'S' && string[i] <= 'Z')
		{
			string[i] = 'R' - (string[i] - 'S');
		}

		if (string[i] == '\0') break;
	}
}

void decoding(char* string, int sizeOfString)
{
	int i;
	for (i = 0; i < sizeOfString - 1; i++)
	{
		//decode '0'-'9' to 'A'-'J' 
		if (string[i] >= '0' && string[i] <= '9')
		{
			string[i] = string[i] + ('A' - '0');
		}

		//decode 'K'-'R' to 'Z'-'S'
		if (string[i] >= 'K' && string[i] <= 'R')
		{
			string[i] = ('R' - string[i]) + 'S';
		}
		//decode 'Z'-'S' to 'K'-'R'
		else if (string[i] >= 'S' && string[i] <= 'Z')
		{
			string[i] = 'R' - (string[i] - 'S');
		}

		if (string[i] == '\0') break;
	}
}
