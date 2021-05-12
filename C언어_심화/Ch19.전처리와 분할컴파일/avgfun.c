#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_d(int* pa, int* pb)
{
	printf("두 정수 값을 입력하세요");
	scanf("%d %d", pa, pb);
}

double average(int a, int b)
{
	return (a + b) / 2;
}