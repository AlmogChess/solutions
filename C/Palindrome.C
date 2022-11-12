#include <stdio.h>
#include <ctype.h>

int main()
{
	char s[] = "Madam! I'm Adam";
	int j = 0;

	while (s[j] != NULL)
	{
		printf("%c when j = %d \n", s[j], j);
		j = j + 1;
	}

	j = j - 1;

	int cpyj = j;
	printf("%d \n", cpyj);

	for (int i = 0; i < cpyj; i++)
	{
		    s[i] = tolower(s[i]);
	}

	for (int i = 0; i < cpyj; i++)
	{
		if ((((s[i] >= 64)  && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) && 
		(((s[cpyj] >= 64)  && (s[cpyj] <= 90)) || ((s[cpyj] >= 97) && (s[cpyj] <= 122))))
		{
		if (s[i] != s[cpyj])
		{
			printf("this is not Palindrome char");
			printf("%c : %c \n", s[i], s[cpyj]);
		}
		}

		cpyj = cpyj - 1;
	}
}
