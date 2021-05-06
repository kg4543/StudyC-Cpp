#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void print_stu_sco(int(*pscore)[4]);
void print_sub_sco(int(*pscore)[4]);
void subject(int i);

int question2()
{
	printf("\n--------------\n");

	/// 학생 5명
	/// 국어,영어,수학,과학 점수 총점



	int score[5][4];
	int* stutotal;
	int* subtotal;
	int i, j;

	for (i = 0; i < 5; i++)
	{
		printf("%d 번 학생 점수 입력...\n", i + 1);
		for (j = 0; j < 4; j++)
		{
			subject(j);
			printf(" 점수 : ");
			scanf("%d", &score[i][j]);
		}
	}

	printf("\n-----------------------------\n"); 
	printf("학생별 점수 현황");
	printf("\n-----------------------------\n");
	/*stutotal = cal_stu_score(score);
	subtotal = cal_sub_score(score);*/
	print_stu_sco(score);
	printf("\n-----------------------------\n"); 
	printf("과목별 점수 현황");
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
		printf("%d 번 학생 점수...\n", i + 1);
		total = 0;
		for (j = 0; j < 4; j++)
		{
			subject(j);
			total += pscore[i][j];
			printf("점수 : %d\n", pscore[i][j]);
		}
		avg = total / 4.0;
		printf("\n총합 : %d , 평균 : %.1lf ", total, avg);
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
		printf("\n총합 : %d , 평균 : %.1lf \n", total, avg);
		printf("\n----------------------------\n");
	}
}

void subject(int i)
{
	switch (i)
	{
	case 0: printf("국어"); break;
	case 1: printf("영어"); break;
	case 2: printf("수학"); break;
	case 3: printf("과학"); break;
	}
}