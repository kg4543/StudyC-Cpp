#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sub3()
{
	printf("\n--------------\n");

	char temp[80];
	char* str[3];
	int i;

	for ( i = 0; i < 3; i++)
	{
		printf("���ڿ��� �Է��ϼ���!!!\n");
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1); //���ڿ� ���� �Ҵ�
		strcpy(str[i], temp); // �Ҵ� ������ ���ڿ� ����
	}

	for ( i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}

	for ( i = 0; i < 3; i++)
	{
		free(str[i]);
	}

	return 0;
}