#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub16()
{
	printf("\n--------------\n");

	char str[80] = "straw";

	strcat(str, "berry"); //문자열 뒤에 추가
	printf("%s\n", str);
	strncat(str, "piece", 3); // 문자열 뒤에 갯수만큼 문자열 추가
	printf("%s\n", str);

	return 0;
}