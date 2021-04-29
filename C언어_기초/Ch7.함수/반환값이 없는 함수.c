#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_char(char , int);

int sub4(void)
{

	printf("\n-------------\n");

	print_char('@', 5);

	return 0;
}

void print_char(char ch,int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%c", ch);
	}

	//return;
}