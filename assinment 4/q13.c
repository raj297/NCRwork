#include <string.h>
#include<stdio.h>
#include <stdlib.h>
void expand(char *s1,char *s2);
int main () {
   char *s1,*s2;
   s1=(char *)malloc(sizeof(char));
   s2=(char *)malloc(sizeof(char));
   scanf("%s",s1);
   printf("%s",s1);
   expand(s1,s2);
   printf("\n expanded \n %s",s2);
}
void expand(char *s1,char *s2)
{char l,h,j=0,i=0;
    while(*(s1+i)!='\0')
    {
        if(*(s1+i+1)!='-')
        {*(s2+j)=*(s1+i);
        j++;
            
        }
        if(*(s1+i)=='-')
        {
            j--;
            l=*(s1+i-1);
            h=*(s1+i+1);
            //printf("%d %d",l,h);
            for(int i1=l;i1<h;i1++)
            {
                *(s2+j)=(char)(i1);
            j++;
                
            }
        }
        i++;
        
    }
}