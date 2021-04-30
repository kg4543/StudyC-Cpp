#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub5()
{
	printf("\n-------------\n");

	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "triger");
	strcpy(str1, str2);
	printf("%s, %s\n", str1, str2);

	return 0;
}