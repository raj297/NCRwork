#include<stdio.h>

int main()
{
    char s[10],c,s1[10];
int i=0,j=0;
printf("enter characters to delete");
scanf("%c",&c);
    scanf("%s",s);
while(s[i]!='\0')
{
if(s[i]!=c)
    { 
       
        s1[j]=s[i];
        j++;
    }
    i++;
}s1[j]='\0';
printf("\n %s",s1);
    
	return 0;
}