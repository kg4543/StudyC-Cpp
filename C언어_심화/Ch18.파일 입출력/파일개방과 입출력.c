#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub0()
{
	FILE* fp;

	fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);

	return 0;
}

//Stream 자동으로 만들어줌 
//1. 입력(stdin) 
//2. 출력(stdout) 
//3. 에러(stderr)  