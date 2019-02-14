#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *s2=(char *)malloc(sizeof(char));
    char *s1=(char *)malloc(sizeof(char));
   
    scanf("%s",s1);
    scanf("%s",s2);
    int i=0,j=0,c=0;
	strcat(s1,s2);
	//*s2=*s1;
		printf("%s \n",s1);
	while(*(s1+i)!='\0')
{
   // printf("s1 i_____%c \n",*(s1+i));
	                     for(int k=0;k<j;k++)
	                         { // printf("s2 i_____%c \n",*(s2+k));
	                             if(*(s1+i)==*(s2+k))
	                                 {
	                                     c++;
	                                 }
	                          }
	                    if(c==0)
	                     {
	                         *(s2+j)=*(s1+i);
	                           j++;
	                        }
	               c=0;                  
	          i++;
}
	printf("\n %s",s2);
   // printf("%s",s2);

	

	return 0;
}
