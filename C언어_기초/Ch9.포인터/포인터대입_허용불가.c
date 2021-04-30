#include <stdio.h>

int sub5()
{
	printf("\n-------------\n");

	int a = 10;
	int* p = &a;
	double* pd;

	pd = p; // 자료형이 달라서 값이 이상하게 출력
	printf("%.1lf\n", *pd);

	return 0;
}