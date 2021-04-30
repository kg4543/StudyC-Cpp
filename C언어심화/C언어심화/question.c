#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void input_array(int* pa, int size);
void swap_array(int* pa, int* pb, int size);
void print_array(int* pa, int size);


int question(void)
{
	printf("\n--------------\n");

	int ary[10];
	int size = sizeof(ary) / sizeof(ary[0]);

	input_array(ary, size);
	print_array(ary, size);
	printf("\n--------------\n");
	swap_array(ary, ary+(size-1),size);
	print_array(ary, size);
}

void input_array(int* pa, int size)
{
	int i;

	for ( i = 0; i < size; i++)
	{
		scanf("%d", pa);
		pa++;
	}
}

void print_array(int* pa,int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}

void swap_array(int* pa, int* pb,int size)
{
	int i;
	int temp;

	for (i = 0; i < size/2; i++)
	{
		temp = *pb;
		*pb = *pa;
		*pa = temp;
		pa++;
		pb--;
	}
}