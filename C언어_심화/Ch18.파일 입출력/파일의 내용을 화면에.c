#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub1()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); //상대경로로 파일열기
	if (fp == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
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