#include <stdio.h>
int main()
{
    int i, s, n, c= 0;

   
    scanf("%d",&n);

    for(i=1; i<=n; ++i)
    {
        for(s=0; s <n-i; ++s)
        {
            printf(" ");
           
        }
    c=i;
    while(c>=1)
    {
        printf("%d",c);
        c--;
    }
      c++;
        while(c<i)
       {c++;
           printf("%d",c);
        }
    
    printf("\n");}
    
    return 0;
}
