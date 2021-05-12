#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub8()
{
	printf("\n--------------\n");

	char str[80];
	printf("문자열 : ");
	scanf("%s", str);
	printf("첫 번째 단어 : %s\n", str);
	scanf("%s", str);
	printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

	return 0;
}