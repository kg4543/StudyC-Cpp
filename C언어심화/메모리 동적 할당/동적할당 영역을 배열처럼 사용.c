#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub1()
{
	printf("\n--------------\n");

	int* pi;
	int i, sum = 0;

	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		printf("메모리가 부족합니다.\n");
		exit(1);
	}

	printf("다섯명의 나이를 입력하세요 : ");
	for ( i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]);
		sum += pi[i];
	}
	printf("다섯명의 평균 나이 : %.1lf\n", (sum/5.0));
	free(pi);

	return 0;
}