#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub2()
{
	printf("\n--------------\n");

	char animal[5][20];
	int i;
	int count;

	count = sizeof(animal) / sizeof(animal[0]);
	for ( i = 0; i < count; i++)
	{
		scanf("%s", animal[i]);
	}

	for ( i = 0; i < count; i++)
	{
		printf("%s ", animal[i]);
	}

	return 0;
}