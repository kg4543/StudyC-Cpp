#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub0()
{
	FILE* fp;

	fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		return 1;
	}
	printf("������ ���Ƚ��ϴ�.\n");
	fclose(fp);

	return 0;
}

//Stream �ڵ����� ������� 
//1. �Է�(stdin) 
//2. ���(stdout) 
//3. ����(stderr)  