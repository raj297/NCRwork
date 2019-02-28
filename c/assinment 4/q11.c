#include <string.h>
#include <stdio.h>

int main () {
   char str[80] ;
   printf("enter the string \n");
   scanf("%s",str);
   const char s[2];
   printf("enter the delimiter \n ");
   scanf("%s",s);
   char *token;
   
   
   token = strtok(str, s);
   
   
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);//not clear??
   }
   
   return(0);
}