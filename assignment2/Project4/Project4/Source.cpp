#include<stdio.h>
#include<math.h>
int main()
{
int l=0,num=0,n,c=0;
scanf_s("%d",&n);
while(n>0&&c<4)
{
l=n%10;
num=num+l*pow(2,c++);
n=n/10;
if(c==3&&n>0)
{
	if (num<10)
	{
		printf("%d", num);
	}
    else
        {
switch(num)
{
case 10:
printf("A");
break;
case 11:
printf("B");
break;
case 12:
printf("C");
break;

case 13:
	printf("D");
	break;

case 14:
	printf("E");
	break;

case 15:
	printf("F");
	break;
	}

}
c = 0;num = 0;

}

}
scanf_s("%d",&num);


}