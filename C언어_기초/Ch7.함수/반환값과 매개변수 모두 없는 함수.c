#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_line();

int sub5(void)
{

	printf("\n-------------\n");

	print_line();
	printf("�й� �̸� ���� ����\n");
	print_line();

	return 0;
}

void print_line()
{
	int i;

	for (i = 0; i < 50; i++)
	{
		printf("-");
	}
	printf("\n");
}