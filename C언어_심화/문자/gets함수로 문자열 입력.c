#define _CRT_CECURE_NO_WARNINGS
#include <stdio.h>

int sub9()
{
	printf("\n--------------\n");

	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str);
	printf("입력한 문자열은 %s입니다.", str);

	return 0;
}