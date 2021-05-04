#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub17()
{
	printf("\n--------------\n");

	char str1[80], str2[80];
	char* resp;

	printf("2개의 과일 이름 입력 : ");
	scanf("%s%s", str1, str2);
	if (strlen(str1)>strlen(str2))
	{
		resp = str1;
		printf("이름이 긴 과일은 : %s\n", resp);
	}
	else if (strlen(str1) < strlen(str2)) // strlen : 문자열 길이
	{
		resp = str2;
		printf("이름이 긴 과일은 : %s\n", resp);
	}
	else
	{
		printf("길이가 동일합니다.");
	}

	return 0;
}