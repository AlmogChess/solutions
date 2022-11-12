int Palindrome(char *s)
{
	char s1[] = "Madam! I'm Adam";

	size_t i = 0, size = 0, counter = 0, notalpha = 0;
	
	size = strlen(s1) - 1;

	for (i = 0; i < size; ++i)
	{
	
		if ((0 != isalpha(s1[i])) && (0 != isalpha(s1[size-i])))
		{
			if ((tolower(s1[size-i])) == (tolower(s1[i])))
			{
				++counter;
			}
			else
			{
				printf("No, for %d ! %d \n", tolower(s1[size-i]), tolower(s1[i]));
			}
		}
		else
		{
			++notalpha;
		}
	}
	
	if ((counter) == (size - notalpha))
	{
		printf("yes\n");
		return 1;
	}
		
	return 0;
}
