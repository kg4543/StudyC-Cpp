
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void print_ary(int* pa);

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub3(void)
{
	printf("\n--------------\n");

	int ary[5] = { 10, 20, 30, 40, 50 };
	
	print_ary(ary);

	return  0;
}

void print_ary(int *pa)
{
	int i;

	for ( i = 0; i < 5; i++)
	{
		printf("%d", pa[i]);
	}
}