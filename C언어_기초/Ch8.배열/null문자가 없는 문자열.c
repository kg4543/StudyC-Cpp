#include<stdio.h>

int sub7(void)
{
	printf("\n-------------\n");

	char str[5];

	str[0] = '0';
	str[1] = 'K';
	str[2] = '\0'; //null 문자, 없을 경우 쓰레기값
	printf("%s\n", str);

	return 0;
}