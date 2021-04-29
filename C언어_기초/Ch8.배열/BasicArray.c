#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub0()
{
	int ary[5];
	
	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	printf("°ª ÀÔ·Â:");
	scanf("%d", &ary[3]);

	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);
	printf("%d\n", ary[4]);

	return 0;
}