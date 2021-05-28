#include <stdio.h>

void swap(int& ra, int& rb);

void sub9()
{
	int a = 10, b = 20;
	printf("a : %d, b : %d\n", a, b);
	swap(a, b);
	printf("a : %d, b : %d\n", a, b);
}

void swap(int& ra, int& rb)
{
	printf("바꾸는 중...\n");
	int temp;
	temp = ra;
	ra = rb;
	rb = temp;
}