#include<stdio.h>
int pow(int a, int b)
{
	while (b-->0)
	{
		a = a*2;
		printf("%d   ", a);
	}
	return a;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("enter the idx to start inversion and number of bits");
	int idx, b;
	scanf_s("%d", &idx);
	scanf_s("%d", &b);
	int temp,i=0;
	temp=(pow(1, b ) - 1) << idx;
    printf("%d", temp^n);
	getchar();
	getchar();
	return 0;
}