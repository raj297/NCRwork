
#include<stdio.h>
#include<string.h>
void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void div(int a, int b);
 int res=0;
int main()
{
int operand=0;
char  oper;
char str[3];
printf("---------------------------------CALCULATOR DEMO--------------------------------\n				(PRESS $ TO EXIT)\n");
	while (1)
	{
		printf("result--->%d \n enter \n",res);
		gets(str);
		//printf("%s", str);
		oper = str[0];
		int i =0;
		
		operand = str[1];
		//multiple digits
		/*
		while (i++<strlen(str)) {
			printf("--------------%d",str[i]);
			operand = 10 * operand + (str[i]);
		}*/
		switch (oper)
		{
		case '+':
			add(res, operand-48);
			break;
		case '-':
			sub(res, operand-48);
			break;
		case '*':
			mul(res, operand-48);
			break;
		case '/':
			div(res, operand - 48);
			break;
		case '$':
			exit(1);
			break;
		default:
			printf("\nENTER THE RIGHT OPERAND\n");
			break;
		}
	}
	int n;
	scanf_s("%d",&n);
	return 0;
}