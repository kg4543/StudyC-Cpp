#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int* cal_stu_score(int** pscore);
int* cal_sub_score(int** pscore);
void print_stu_score(int** pscore, int* pstu);
void print_sub_score(int** pscore, int* psub);

int question4()
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
			scanf("%d", &score[i][j]);
		}
	}

	stutotal = cal_stu_score(score);
	printf("%d", *stutotal);
	/*subtotal = cal_sub_score(score);
	print_stu_score(score,stutotal);
	print_sub_score(score,subtotal);*/

}

int* cal_stu_score(int(* pscore)[4])
{
	int i, j;
	int stutemp = 0;
	int stutotal[5];

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", pscore[i][j]);
			stutemp += pscore[i][j];
			stutotal[i] = stutemp;
		}
	}
	return stutotal;
}

int* cal_sub_score(int(*pscore)[4])
{
	int i, j;
	int subtemp = 0;
	int subtotal[5];

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			subtemp += pscore[j][i];
			subtotal[i] = subtemp;
		}
	}

	return subtotal;
}

void print_stu_score(int(*pscore)[4], int* pstu)
{
	int i, j;
	int total;
	double avg;

	for (i = 0; i < 5; i++)
	{
		printf("%d 번 학생 점수...\n", i + 1);

		for (j = 0; j < 4; j++)
		{
			printf("%5d", pscore[i][j]);
		}
		total = pstu[i];
		avg = pstu[i] / 5.0;
		printf("\n총합 : %d , 평균 : %.1lf ", total, avg);
		printf("\n----------------------------\n");
	}
}

void print_sub_score(int(*pscore)[4], int* psub)
{
	int i, j;
	int total;
	double avg;

	for (i = 0; i < 4; i++)
	{
		printf("%d 번 과목 점수...\n", i + 1);

		/*for (j = 0; j < 5; j++)
		{
			printf("%5d", pscore[j][i]);
		}*/
		total = psub[i];
		avg = psub[i] / 4.0;
		printf("\n총합 : %d , 평균 : %.1lf \n", psub[i], avg);
		printf("\n----------------------------\n");
	}
}