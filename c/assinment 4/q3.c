#include <string.h>
#include<stdio.h>

int main () {int c=0;
 char * s[] = {
"we will teach you how to"  ,
"Move a mountain" ,
"Level a building " ,
"Erase the past ",
"Make a million" };
for(int i=0;i<5;i++)
{
    char *p=*s+i;
    while(*p!='\0')
    {
        if(*p=='e')
        c++;
        p++;
    }
   // printf("c=%d",c);
}
printf("%d",c);

}