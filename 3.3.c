#include <stdio.h>



void expand(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;
	while ((c = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i + 1] >= c)
		{
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
		s2[j] = '\0';
	}
}

void test2()
{
	char* s[] = { "a-z-", "a-b-c", "a-z0-9", "-a-z", NULL};
	char result[100];
	int i = 0;

	while (s[i]) {
		expand(s[i], result);
		printf("Unexpanded: %s\n", s[i]);
		printf("Expanded  : %s\n", result);
		++i;
	}
}

int main(void)
{
	test2();
	return 0;
}