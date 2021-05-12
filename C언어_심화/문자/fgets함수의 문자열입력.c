#define _CRT_CECURE_NO_WARNINGS
#include <stdio.h>

int sub10()
{
	printf("\n--------------\n");

	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	fgets(str, sizeof(str), stdin); //stdin:  표준입력.stream 구조체 활용
	printf("입력된 문자열은 %s입니다.\n", str);

	return 0;
}