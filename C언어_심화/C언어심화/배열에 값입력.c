#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void input_ary(int* pa, int size);
double find_max(double* pa, int size);


int sub5(void)
{
	printf("\n--------------\n");

	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]); // �迭 ����

	input_ary(ary, size); //�迭���� ��ŭ �� �Է�
	max = find_max(ary, size); //�迭 �� �ִ밪 ���ϱ�
	printf("�迭�� �ִ밪 : %.1lf\n",max);

	return 0;
}

void input_ary(double* pa, int size)
{
	int i;

	printf("%d���� �Ǽ��� �Է� \n", size);
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
	for (i = 1; i < size; i++) // �ִ밪 ã��
	{
		if (pa[i] > max) {
			max = pa[i];
		}
	}
	
	return max; //�ִ밪 ��ȯ
}