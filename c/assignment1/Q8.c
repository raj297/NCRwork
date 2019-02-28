//8.....
/*Sall*/
#include<stdio.h>

int main() {
 float n,sum=0;
 /*Basic HRA DA .
1 - 4000 10% 50%
4001 - 8000 20% 60%
8001 - 12000 25% 70%
12000 and above 30% 80%*/
  //printf("enter a number ");
  scanf("%f",&n);
  float hr=0,dr=0;
  if(n>=1&&n<=4000)
  {
      hr=hr+(n*(1.10));
  dr=dr+(n*(1.50));
  }
  else if(n>=4001&&n<=8000)
  {
      
      hr=hr+(n*(1.20));
  dr=dr+(n*(1.60));
  }
  else if(n>=8001&&n<=12000)
  {
      
      hr=hr+(n*(1.25));
  dr=dr+(n*(1.70));
  }
  else if(n>=12001)
  {
      
      hr=hr+(n*(1.30));
  dr=dr+(n*(1.80));
  }
  sum=n+hr+dr;
  printf("%.0f",sum);
  
  
    return 0;
}
