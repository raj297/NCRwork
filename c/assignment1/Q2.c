//2.............
#include<stdio.h>

int main() {
 int num=0,alpha=0,p=0,tab=0,sp=0,flag=1;
 char str[80];
 scanf("%s",str);
 printf("%s",str);
 for(p=0;str[p]!=-1;p++)
 {
     // printf("%d",str[p]);
     if(str[p]>=65&&str[p]<=90)
     {
         alpha++;
     }
     
     
     if(str[p]>=48&&str[p]<=57)
     {
         num++;
     }
     
     if(str[p]==32)
     {
         sp++;
        
     }
    
 }
 printf("%d \n %d \n %d",alpha,num,sp);
    return 0;
}