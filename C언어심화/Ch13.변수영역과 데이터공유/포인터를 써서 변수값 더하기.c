#include <stdio.h>

void add_ten(int* pa);

int sub5()
{
	printf("\n--------------\n");

	int a = 10;

	add_ten(&a);
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int* pa)
{
	*pa = *pa + 10;
}