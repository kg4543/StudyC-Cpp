#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub4()
{
	printf("\n-------------\n");

	char str[80] = "applejam";

	printf("최초 문자열 : %s\n",str);
	printf("문자열 : ");
	scanf("%s",str);
	printf("입력 후 문자열 : %s\n", str);

	return 0;
}