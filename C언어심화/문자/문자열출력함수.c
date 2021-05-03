#define _CRT_CECURE_NO_WARNINGS
#include <stdio.h>

int sub12()
{
	printf("\n--------------\n");

	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);
	fputs(ps, stdout);
	puts("milk");

	return 0;
}