
#include<stdio.h>
#include<math.h>
double pow(double x,double y)
{double t=x;
    while(y-->0)
    {
        t=t*x;
    
    //    printf("%lf",x);
    }
    return x;

    
}
int main() {
 double p=500000,t=10,n,r=1;
double si=0,A;
si=(p*t*r)/100;
  printf("Amount with SI = %.2lf",(p+si));
 
  printf("\nCI compounded Anually=");
  n=1;
  A=p*pow((1+(r/n)),(n*t));
  printf("%.2lf",A);
  printf("\nCI compounded HalfYearly=");
  n=2;
  A=p*pow((1+(r/n)),(n*t));
  printf("%.2lf",A);
  printf("\nCI compounded Quaterly=");
  n=4;
  A=p*pow((1+(r/n)),(n*t));
  printf("%.2lf",A);
  printf("\nCI compounded montly=");
  n=12;
  A=p*pow((1+(r/n)),(n*t));
  printf("%.2lf",A);
  printf("\nCI compounded Daily=");
  n=365;
  A=p*(pow((1+(r/n)),(n*t)));
  printf("%.2lf",A);
    return 0;
}
