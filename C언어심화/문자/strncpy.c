#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub15()
{
	printf("\n--------------\n");

	char str[20] = "mango tree";

	strncpy(str, "apple-pie", 5); //�� 5���ڸ� ���� ��ü

	printf("%s\n", str);

	return 0;
}