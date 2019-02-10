#include<stdio.h>
int fact(int);
int main()
{int n=5,f;
scanf_s("%d",&n);
f=fact(n);
printf("%d",f);
getchar();
}
int fact(int n)
{
if(n==1)
return 1;
else
return n*fact(n-1);
}