#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub1()
{
	printf("\n--------------\n");

	char ch1, ch2;

	scanf("%c%c", &ch1, &ch2);

	printf("[%c%c]", ch1, ch2);

	return 0;
}