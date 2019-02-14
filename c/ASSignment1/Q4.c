///*Amstrong Yes/no*/
#include<stdio.h>

int main() {
 int n,sum=0;
  //printf("enter a number ");
  scanf("%d",&n);
  int t=n;
  while(n>0)
  {
      int t1=n%10;
sum=sum+(t1*t1*t1);
n=n/10;
  }
  if(t==sum)
  printf("yes! Amstrong");
  else
  printf("No!");

    return 0;
}