#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub1()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); //����η� ���Ͽ���
	if (fp == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp); 
		if (ch == EOF) //EOF(End Of File) : -1
		{
			break;
		}
		putchar(ch);
	}
	fclose(fp);

	return 0;
}