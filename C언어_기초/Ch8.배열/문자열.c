#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub4()
{
	printf("\n-------------\n");

	char str[80] = "applejam";

	printf("���� ���ڿ� : %s\n",str);
	printf("���ڿ� : ");
	scanf("%s",str);
	printf("�Է� �� ���ڿ� : %s\n", str);

	return 0;
}