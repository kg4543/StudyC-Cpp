#include<stdio.h>

int sub7(void)
{
	printf("\n-------------\n");

	char str[5];

	str[0] = '0';
	str[1] = 'K';
	str[2] = '\0'; //null ����, ���� ��� �����Ⱚ
	printf("%s\n", str);

	return 0;
}