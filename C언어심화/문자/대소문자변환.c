#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub0() 
{
	char small, cap = 'G';

	if ((cap>='A') && (cap <='Z'))
	{
		small = cap + ('a' - 'A');
	}

	printf("�빮�� : %c %d\n", cap, cap);
	printf("�ҹ��� : %c %d\n", small, small);

	return 0;
}