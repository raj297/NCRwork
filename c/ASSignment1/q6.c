#include<stdio.h>
void main()
{
	unsigned int num;
	int a[5], i,j;
	printf("Enter a number :");
	scanf_s("%d", &num);
	if (num < 32)
	{
		for (i = 0;i < 5;i++)
		{
			a[i] = num % 2;
			num = num/2;
		}
		
		while (a[i] == 0)
			i--;
		for (j = i;j >= 0;j--)
		{
			printf("%d", a[j]);
		}

	}
	else
		printf(" greater than 31");
	getch();
}
