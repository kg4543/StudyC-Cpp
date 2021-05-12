#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub3()
{
	printf("\n--------------\n");
	
	char ch;
	int i;

	for ( i = 0; i < 6; i++)
	{
		scanf("%c", &ch);
		printf("%c", ch);
	}

	return 0;
}