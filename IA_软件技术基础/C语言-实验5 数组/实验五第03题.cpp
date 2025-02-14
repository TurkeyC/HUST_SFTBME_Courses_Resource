#include<stdio.h>
#include<string.h>

void RemoveDuplicate(char []);

int main()
{
	char str[200];
	printf("Input strings, end of Ctrl+z\n");
	while(fgets(str, 200, stdin) != NULL)
	{
		RemoveDuplicate(str);
		printf("%s", str);
	}
   return 0;
}

void RemoveDuplicate(char *s)
{
	int judge[256] = {0};
	int r, w, i, len;
	len = strlen(s);
	for (r = w = 0; r < len; r++)
	{
		if(s[r] != '\0')
		{	if(judge[s[r]] == 0) judge[s[r]] = 1;
			else continue;
			if(judge[s[r]] == 1) s[w++] = s[r];
		}
	}
	s[w] = '\0';
}