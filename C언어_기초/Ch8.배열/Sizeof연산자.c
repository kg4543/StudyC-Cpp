#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub2()
{
	printf("\n-------------\n");

	int score[5];
	int i;
	int total = 0;
	double avg;
	int count;

	count = sizeof(score) / sizeof(score[0]);

	for ( i = 0; i < count; i++)
	{
		scanf("%d", &score[i]);
	}

	for ( i = 0; i < count; i++)
	{
		total += score[i];
	}

	avg = total / (double)count;

	for ( i = 0; i < count; i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("ЦђБе : %.1f\n", avg);

	return 0;

}