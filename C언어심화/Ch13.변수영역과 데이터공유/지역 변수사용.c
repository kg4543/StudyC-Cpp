#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void assign(void);

int sub0()
{
	printf("\n--------------\n");

	auto int a = 0;
	assign();
	printf("main �Լ� a : %d\n",a);

	return 0;
}

void assign(void)
{
	int a;

	a = 10;
	printf("assign �Լ� a : %d\n", a);
}