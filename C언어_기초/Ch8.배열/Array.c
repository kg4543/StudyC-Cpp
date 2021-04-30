#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub3()
{
	printf("\n-------------\n");

	int ary[5] = { 10, 20, 30, 40, 50 };
	int i;
	int size = sizeof(ary) / sizeof(ary[0]); // sizeof(ary) = 4(int) * 5 =20

	for ( i = 0; i < size; i++)
	{
		printf("ary[%d] : %d\n",i,ary[i]);
	}

	printf("\n-------------\n");

	for (i = size-1; i >= 0; i--)
	{
		printf("ary[%d] : %d\n", i, ary[i]);
	}

	return 0;
}