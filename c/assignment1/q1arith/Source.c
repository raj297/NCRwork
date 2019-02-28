#include<stdio.h>
void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
 int res;
int main()
{
	int a = 1, b = 2;
	add(a, b);
	printf("%d \n", res);
	sub(a, b);
	printf("%d \n", res);
	mul(a, b);
	printf("%d \n", res);
	getchar();
	return 0;
}