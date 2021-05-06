#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int (*fp)(int, int));
int summ(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int sub8()
{
	printf("\n--------------\n");
	
	int sel;

	printf("01 두 정수의 합\n");
	printf("02 두 정수의 곱\n");
	printf("03 두 정수에서 큰 값\n");
	printf("원하는 연산을 선택하세요 : ");
	scanf("%d", &sel);

	switch (sel)
	{
		case 1: func(summ); break;
		case 2: func(mul); break;
		case 3: func(max); break;
	}

	return 0;
	
}

void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("두 정수의 값을 입력하세요 : ");
	scanf("%d%d", &a, &b);

	res = fp(a, b);
	printf("결과값은 : %d\n", res);
}

int summ(int a, int b)
{
	return (a + b);
}

int mul (int a, int b)
{
	return (a * b);
}

int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
	
}
