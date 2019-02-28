#include<stdio.h>
void itob(int n);
int p(int n)
{int n1=1;
while(n-->0)
    n1=n1*2;
    return n1;
}
void itoh(int n);
int main() {
  int n,r=0;
  scanf("%d",&n);
  itob(n);
 itoh(n);
}
void itoh(int n)
{
    printf("itoh");
 printf("%x",n);
 
}

void itob(int n)
{
 int a[16]={0},i=0;
 while(n>0)
 {
     a[i++]=n%2;
     n=n/2;
 }
 for(int j=i-1;j>=0;j--)
 printf("%d",a[j]);
}
