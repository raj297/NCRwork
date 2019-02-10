#include <stdio.h>
int main()
{
    int n,r=0;
    scanf("%d",&n);
int num=n;
while(n>0)
{
    r=r*10+n%10;
    n=n/10;
}
    
    if(num-r==0)
    printf("Yess");
    else
    printf("No");
    
    return 0;
}
