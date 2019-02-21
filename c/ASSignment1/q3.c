#include<stdio.h>
int main()
{
	int n;
	scanf_s("%x", &n);

	int temp = n;
	int i = 0, cnt = 0;;
	while (temp > 0&&i++<4)
	{
		if (temp & 1)
		{
			cnt++;
		}
		
		temp = temp >> 1;
	}
	if (cnt == 3)
		printf("yes 3 bits are set");
	else
		printf("NO");
	//produce feca
	temp= n;
	int num,temp2 = n;
	temp= temp >> 8;
	temp2 = temp2 << 8;
	num= (temp | temp2) &0xffff;
	printf("\n %x",num);
	//preoduce ecaf
	temp = n;
	i = temp&0x000f;
	i = i << 12;
	temp = temp >>4;
	
	printf("\n %x", i|temp);
	getchar();
	getchar();
	return 0;
}