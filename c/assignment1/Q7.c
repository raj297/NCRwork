
//7..............
#include<stdio.h>

int main() {
 int n=1,sum=0,p=0,min=65535,max=0;
 while(n!=0)
 {
  //  printf("sdasd");
     scanf("%d",&n);
     if(n>0)
     {
         p++;
         sum=sum+n;
         if(n<=min&&n!=0)
         min=n;
         else if(n>max)
         max=n;
         
     }
     
 }
 printf("sum=%d \n min=%d \n max=%d",sum,min,max);
 
    return 0;
}
