#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub4()
{
	printf("\n--------------\n");

	int res;
	char ch;

	while (1)
	{
		res = scanf("%c", &ch);
		if (res == -1)
		{
			break;
		}
		printf("%d ", ch);
	}
	return 0;
}