#include<stdio.h>
int main()
{
int a,b;
scanf_s("%d%d",&a,&b);
for(int i=a;i<=b;i++)
{
for(int j=2;j*j<=i;j++)
{
if(i%j==0)
c++;

}
if(c<1)
{
printf("%d\n",i);
}
c=0;
}
return 0;
}