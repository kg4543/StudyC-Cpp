#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub13()
{
	printf("\n--------------\n");

	int i = 0;
	char str[20];
	char ch;

	do
	{
		ch = getchar();
		str[i] = ch;
		i++;
	} while (ch != '\n');

	str[i] = '\0';
	printf("%s", str);
	return 0;
}