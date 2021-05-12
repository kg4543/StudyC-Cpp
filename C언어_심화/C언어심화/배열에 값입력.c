#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void input_ary(int* pa, int size);
double find_max(double* pa, int size);


int sub5(void)
{
	printf("\n--------------\n");

	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]); // 배열 갯수

	input_ary(ary, size); //배열갯수 만큼 값 입력
	max = find_max(ary, size); //배열 중 최대값 구하기
	printf("배열의 최대값 : %.1lf\n",max);

	return 0;
}

void input_ary(double* pa, int size)
{
	int i;

	printf("%d개의 실수값 입력 \n", size);
	for ( i = 0; i < size; i++)
	{
		scanf("%lf", pa + i);
	}
}

double find_max(double* pa, int size)
{
	double max;
	int i;

	max = pa[0];
	for (i = 1; i < size; i++) // 최대값 찾기
	{
		if (pa[i] > max) {
			max = pa[i];
		}
	}
	
	return max; //최대값 반환
}