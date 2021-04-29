#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub1()
{
	printf("\n-------------\n");

	int score[5];
	int i;
	int total = 0;
	double avg;

	printf("5과목의 점수를 입력하세요!!\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
	}

	for ( i = 0; i < 5; i++)
	{
		total += score[i];
	}
	avg = total / 5.0;

	for ( i = 0; i < 5; i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : %.1f\n", avg);

	return 0;
}