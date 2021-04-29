#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_num(void);

int sub3(void)
{

	printf("\n-------------\n");

	int result;

	result = get_num();
	printf("반환값 : %d", result);
	
	return 0;
}

int get_num()
{
	int num;
	printf("양수 입력 : ");
	scanf("%d", &num);

	return num;
}