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

	printf("pb - pa : %u\n",pb-pa); // = (값의 차) / sizeof(int)
	
	printf("앞에 있는 배열 요소의 값 출력 :");
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
