#define _CRT_CECURE_NO_WARNINGS
#include <stdio.h>

int sub10()
{
	printf("\n--------------\n");

	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin); //stdin:  ǥ���Է�.stream ����ü Ȱ��
	printf("�Էµ� ���ڿ��� %s�Դϴ�.\n", str);

	return 0;
}