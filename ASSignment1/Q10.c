//10.............
/*sum of digits*/
#include<stdio.h>

int main() {
 int n,sum=0;
  //printf("enter a number ");
  scanf("%d",&n);
  
  while(n>0)
  {
      int t1=n%10;
sum=sum+(t1);
n=n/10;
  }
 
  printf("Sum=%d",sum);
  
    return 0;
}
