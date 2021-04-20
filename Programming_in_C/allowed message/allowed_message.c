#include <stdio.h>

void getString(char* string, int size);
void scanLimited(char* str, char* allow);

int main()
{
	char allow[31], str[501];

	printf("enter letters which should be allowed (max 30 letters): ");
	getString(allow, sizeof(allow));
	printf("enter a message (max 500 symbols): \n");
	getString(str, sizeof(str));

	scanLimited(str, allow);
	printf("allowed message: \n%s", str);
}

void getString(char* string, int size)
{
	int i;
	for (i = 0; i < size - 1; i++)
	{
		string[i] = getchar();
		if (string[i] == '\n' || string[i] == '\r')
		{
			i++;
			break;
		}
	}
	string[i] = '\0';
}

void scanLimited(char* str, char* allow)
{
	//cycle through main str (text)
	for (int i = 0; str[i]; i++)
	{
		//back up value
		char temp = str[i];

		//cycle through allowed chars
		for (int j = 0; allow[j]; j++)
		{
			if (temp == allow[j])
			{
				str[i] = temp;
				break;
			}
			else if (temp != allow[j])
			{
				str[i] = ' ';
			}
		}
	}
}


