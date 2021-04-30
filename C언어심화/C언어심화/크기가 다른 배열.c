#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void print_ary1(int* pa, int size);

int sub4(void)
{
	printf("\n--------------\n");

	int ary1[5] = { 10,20,30,40,50 };
	int ary2[7] = { 10,20,30,40,50,60,70 };

	print_ary1(ary1, 5);
	printf("\n");
	print_ary1(ary2, 7);

	return 0;
}

void print_ary1(int* pa, int size)
{
	int i;

	for ( i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}
