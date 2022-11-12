int Palindrome(char *s1)
{

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
				/*Option to print where is not equal */
				/* printf("No, for %c ! %c \n", tolower(s1[size-i]), tolower(s1[i])); */
			}
		}
		else
		{
			++notalpha;
		}
	}
	
	if ((counter) == (size - notalpha))
	{
		/* printf("yes\n");*/ 
		return 1;
	}
		
	return 0;
}

void TestPalindrome()
{

	char *s1 = "no way its Palindrome";
	char *s2 = "Madam! I'm Adam";
	size_t size = 2, counter = 0;
	
	if ((Palindrome(s1) == 0))
	{
			counter++;
	}
	if ((Palindrome(s2) == 1))
	{
			counter++;
	}
	
	
	printf("Palindrome succsess for %ld / %ld\n", counter, size);
}
