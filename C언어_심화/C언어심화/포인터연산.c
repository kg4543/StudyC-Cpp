#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub2(void)
{
	printf("\n--------------\n");

	int ary[5] = { 10, 20, 30, 40, 50 };
	int* pa = ary;
	int* pb = pa + 3;
	int i;

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;

	printf("pb - pa : %u\n",pb-pa); // = (���� ��) / sizeof(int)
	
	printf("�տ� �ִ� �迭 ����� �� ��� :");
	if (pa < pb)
	{
		printf("%d\n", *pa);
	}
	else
	{
		printf("%d\n", *pb);
	}
	
	return 0;
}
