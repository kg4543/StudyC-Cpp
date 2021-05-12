#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int sub3(void)
{
	printf("\n--------------\n");

	int ary[5];

	printf("ary의 값 : %u\t", ary);
	printf("ary의 주소 : %u\n", &ary);
	printf("ary + 1 : %u\t", ary + 1);
	printf("&ary + 1 : %u\n", &ary + 1);

	return 0;
}