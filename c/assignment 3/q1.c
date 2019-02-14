#include<stdio.h>

int main() {
 int n=0,sum,r=0,i;
 scanf("%d",&n);
 int a[n];
 for( i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
 scanf("%d",&sum);

int j=0;
 for(i=0;i<n;i++)
 {
     if(r<sum)
      r=r+a[i];
    if(r>sum)
    {
        r=r-a[j];
        j++;
    }
    if(r==sum)
    {
        printf("%d--%d",j,i);
        break;
    }
    
 }

}
