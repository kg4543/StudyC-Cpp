#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub16()
{
	printf("\n--------------\n");

	char str[80] = "straw";

	strcat(str, "berry"); //���ڿ� �ڿ� �߰�
	printf("%s\n", str);
	strncat(str, "piece", 3); // ���ڿ� �ڿ� ������ŭ ���ڿ� �߰�
	printf("%s\n", str);

	return 0;
}