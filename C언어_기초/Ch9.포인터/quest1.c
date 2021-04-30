#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* pa, int* pb);

int a = 10, b = 20;

int question1(void) {

	printf("\n-------------\n");

	//int a = 10, b = 20;

	printf("a: %d, b: %d\n", a, b);

	swap(&a,&b);

	printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp;

	temp = *pb;
	*pb = *pa;
	*pa = temp;
}

