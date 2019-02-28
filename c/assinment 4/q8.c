#include<stdio.h>
#include<stdlib.h>
int main()
{int n;
printf("Enter the number of strings");
scanf("%d",&n);
char *a[n];
for(int i=0;i<n;i++)
{
a[i]=(char *)malloc(sizeof(char));
scanf("%s",a[i]);
    
}
for(int i=0;i<n;i++)
printf("%s \n",a[i]);

	return 0;
}