#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[10];int i=0,j=0;
    scanf("%s",s);
    for( i=0;i<strlen(s);i++)
    {
        for( j=i;j<strlen(s);j++)
      printf("%c",s[j]);
      for(int j1=0;j1<i;j1++)
      printf("%c",s[j1]);
    
        printf("\n");
    }
	//printf("%s",s);

	

	return 0;
}