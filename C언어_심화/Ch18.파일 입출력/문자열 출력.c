#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub2()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	fp = fopen("b.txt", "w");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.");
		return 1;
	}

	i = 0;
	while (str[i] != '\0')
	{
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);

	return 0;
}