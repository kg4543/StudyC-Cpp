#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void print_stu_sco(int(*pscore)[4]);
void print_sub_sco(int(*pscore)[4]);
void subject(int i);

int question2()
{
	printf("\n--------------\n");

	/// �л� 5��
	/// ����,����,����,���� ���� ����



	int score[5][4];
	int* stutotal;
	int* subtotal;
	int i, j;

	for (i = 0; i < 5; i++)
	{
		printf("%d �� �л� ���� �Է�...\n", i + 1);
		for (j = 0; j < 4; j++)
		{
			subject(j);
			printf(" ���� : ");
			scanf("%d", &score[i][j]);
		}
	}

	printf("\n-----------------------------\n"); 
	printf("�л��� ���� ��Ȳ");
	printf("\n-----------------------------\n");
	/*stutotal = cal_stu_score(score);
	subtotal = cal_sub_score(score);*/
	print_stu_sco(score);
	printf("\n-----------------------------\n"); 
	printf("���� ���� ��Ȳ");
	printf("\n-----------------------------\n");
	print_sub_sco(score);

}

void print_stu_sco(int(*pscore)[4])
{
	int i, j;
	int total;
	double avg;

	for (i = 0; i < 5; i++)
	{
		printf("%d �� �л� ����...\n", i + 1);
		total = 0;
		for (j = 0; j < 4; j++)
		{
			subject(j);
			total += pscore[i][j];
			printf("���� : %d\n", pscore[i][j]);
		}
		avg = total / 4.0;
		printf("\n���� : %d , ��� : %.1lf ", total, avg);
		printf("\n----------------------------\n");
	}
}

void print_sub_sco(int(*pscore)[4])
{
	int i, j;
	int total;
	double avg;

	for (i = 0; i < 4; i++)
	{
		subject(i);
		total = 0;
		for (j = 0; j < 5; j++)
		{
			total += pscore[j][i];
		}
		avg = total / 5.0;
		printf("\n���� : %d , ��� : %.1lf \n", total, avg);
		printf("\n----------------------------\n");
	}
}

void subject(int i)
{
	switch (i)
	{
	case 0: printf("����"); break;
	case 1: printf("����"); break;
	case 2: printf("����"); break;
	case 3: printf("����"); break;
	}
}