#include <stdio.h>

void sub8()
{
	int i = 3;
	int& ri = i;
	int* pi = &i;

	printf("i = %d, ri = %d\n",pi, i, ri);
	
	ri++;
	printf("i = %d, ri = %d\n", i, ri);
	*pi = i + 1;
	printf("i = %d, ri = %d\n", i, ri);

	printf("pi = %x ,i번지 = %x, ri번지 = %x\n", pi,&i, &ri);
}