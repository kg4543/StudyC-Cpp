#include <stdio.h>

int sub5()
{
	printf("\n-------------\n");

	int a = 10;
	int* p = &a;
	double* pd;

	pd = p; // �ڷ����� �޶� ���� �̻��ϰ� ���
	printf("%.1lf\n", *pd);

	return 0;
}