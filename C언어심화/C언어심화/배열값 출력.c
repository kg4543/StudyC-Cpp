
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub1(void)
{
	printf("\n--------------\n");

	int ary[3];
	int* pa = ary;
	int i;

	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++)
	{
		printf("%5d", pa[i]);
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("%5d", *(pa + i));
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", *pa); //�����ʹ� �����̱� ������ ���� �����ڰ� �����ϴ�.
		pa++;
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("%d ", *pa + i);
	}

	return 0;
}