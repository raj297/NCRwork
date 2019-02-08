#include<stdio.h>
int main()
{
	char s[10];
	int i=0;
	scanf("%s",s);
	while (s[i] != '\0')
	{
	    if(s[i]>=65&&s[i]<=92)
		s[i] = s[i] +32;
		else if(s[i]<=122&&s[i]>=97)
			s[i] = s[i]-32;
		i++;
	}
	printf("%s", s);
	int c;
	scanf("%d", &c);
	return 0;
}