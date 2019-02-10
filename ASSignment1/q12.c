#include <stdio.h>

int p(int n);
int rotate(int n,int b);
int main()
{
    int n,d=0,b,r=0;
    scanf("%d %d",&n,&b);
  n=rotate(n,b);
   
    printf("\n %d",n);
    
    return 0;
}
int rotate(int n,int b){
int d=0,r=0;
  
    int num=n;
while(num>0)
{   d++;
    num=num/10;
}
printf("%d",d);
while(b-->0)
{
    r=n%10;
    n=(n-r)/10;
    n=r*p(d-2)+n;
   
}
    
   
 return (n);
    }
int p(int e)
{ int n=10;
    
    while(e-->0)
    n=n*10;
    
    
    return n;
    
}