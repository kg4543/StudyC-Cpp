#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub1()
{
	printf("\n--------------\n");

	int num[3][4] =
	{
		{ 1,2,3,4 }, 
		{ 5,6,7,8 }, 
		{9,10,11,12}
	};
	
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", num[i][j]);
		}
		printf("\n");
	}

	return 0;
}