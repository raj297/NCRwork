#include<stdio.h>
#include<string.h>
int main()
{
	char s[3][10],temp[10];
//	int i=0;
	
	for(int i=0;i<3;i++)
	{scanf("%s",s[i]);
	}
	for(int i=0;i<3;i++)
	{
	    for(int j=i+1;j<3;j++)
	    {
	        if(strcmp(s[i],s[j])>0)
	    {
	        strcpy(temp,s[j]);
	        strcpy(s[j],s[i]);
	        strcpy(s[i],temp);
	       	    }
	        
	    }
	}
	    
	
	
		for(int i=0;i<3;i++)
	printf("%s", s[i]);

	return 0;
}