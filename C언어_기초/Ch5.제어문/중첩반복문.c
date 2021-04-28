#include <stdio.h>

int sub8(void) {

	printf("\n-------------\n");
	
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for  (j = 0; j < 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	int max = 6;
	
	printf("\n-------------\n");
	for ( i = 0; i < max; i++)
	{
		for (j = 0; j < max-i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i*2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n-------------\n");
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= (max-i-1)*2; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}