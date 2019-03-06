#include<stdio.h>
extern int res;
void div(int a, int b)
{
	if (b != 0)
		res = a / b;
	else
		printf("\ndivinding by zero??\n");
}