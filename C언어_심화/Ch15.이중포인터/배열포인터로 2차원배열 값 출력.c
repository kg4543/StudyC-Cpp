#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int sub4(void)
{
	printf("\n--------------\n");

	int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int (*pa) [4]; // int�� 4���� �迭�� ����Ű�� �迭 ������ ; 
	// int* pa [4] : int�� 4���� �����Ͱ� �ִ� ������ �迭 
	int i, j;
	pa = ary;

	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}

	return 0;
}