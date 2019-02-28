#include<stdio.h>
#include<math.h>
int main()
{
int n,a[8]={0},i=0,r=0;
scanf_s("%d",&n);
while(n>0&&i<8)
{
//(n>>2)&1
r=n%2;
a[i++]=r;
n=n/2;
}
while(--i>-1)
{
printf("%d",a[i]);

}
printf("vice versa");
int num=0;
while(++i<=7)
{
//printf("%d",num);
num=num+a[i]*pow(2,i);

}
printf("%d",num);


scanf_s("%d",&num);
return 0;
}
 