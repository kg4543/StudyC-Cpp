#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub8()
{
	printf("\n--------------\n");

	char str[80];
	printf("���ڿ� : ");
	scanf("%s", str);
	printf("ù ��° �ܾ� : %s\n", str);
	scanf("%s", str);
	printf("���ۿ� ���� �ִ� �� ��° �ܾ� : %s\n", str);

	return 0;
}