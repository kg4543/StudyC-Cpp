#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub14()
{
	printf("\n--------------\n");

	char str1[80] = "strowberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("최초 문자열 : %s\n", str1);

	strcpy(str1, str2); 
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1); // 문자열 복사 교체
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열 : %s\n", str1);

	return 0;
}
