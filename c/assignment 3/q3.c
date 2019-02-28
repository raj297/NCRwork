#include<stdio.h>

int main() {
 int n=0,c=0;
 scanf("%d",&n);
while(n>0)
   {if(n&1)
   c++;
       n=n>>1;
   }
   printf("%d",c);
}
