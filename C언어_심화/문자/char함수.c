#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub2()
{
	printf("\n--------------\n");

	int ch;
	ch = getchar();
	printf("입력한 문자 : ");
	putchar(ch);
	putchar('\n');

	return 0;
}