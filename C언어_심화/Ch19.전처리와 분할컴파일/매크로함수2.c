#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PRINT_EXPR(x) printf(#x " = %d\n",x)
#define NAME_CAT(x,y) (x ## y) // ##: 2���� ���ڸ� ���δ�.

int sub4()
{
	int a1, a2;

	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 - a1);

	return 0;
}