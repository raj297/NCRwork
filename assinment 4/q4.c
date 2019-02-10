#include <string.h>
#include<stdio.h>
int replace(char *p);
int main () {
 char s[100];
scanf("%[^\n]s",s);
int n=replace(s);
printf("%d",n);
    printf("%s",s);
}
int replace(char *p)
{int s=0;

    while(*(p)!='\0')
     {
         if(*p==' ')
     {
         s++;
         *p='-';
     }
     p++;
         
     }
    return s;
}