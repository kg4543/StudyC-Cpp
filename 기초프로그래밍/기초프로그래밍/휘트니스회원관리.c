#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;

int input_data(Fitness** pary)
{
	int i = 0;
	while (1)
	{
		pary[i] = (Fitness*)malloc(sizeof(Fitness));
		printf("회원 번호 : ");
		scanf("%d", &pary[i]->num);
		if (pary[i]->num < 0)
		{
			free(pary[i]);
			break;
		}
		printf("회원 이름 : ");
		scanf("%s", &pary[i]->name);
		printf("회원 체중 : ");
		scanf("%lf", &pary[i]->weight);
		i++;
	}

	return i; // 0부터 시작하여 -1을 할 필요가 없다.
}

void total_number(int count)
{
	printf("전체 회원 수 : %d 명", count);
}

double average_weight(Fitness** pary, int count)
{
	double sum_weight = 0;
	double avg_weight = 0;

	for (int i = 0; i < count; i++)
	{
		sum_weight += pary[i]->weight;
	}
	avg_weight = sum_weight / count;

	return avg_weight;
}

int max_weight(Fitness** pary, int count)
{
	double max_weight = 0;
	for (int i = 0; i < count; i++)
	{
		if (max_weight < pary[i]->weight)
		{
			max_weight = pary[i]->weight;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (max_weight == pary[i]->weight)
		{
			return i;
		}
	}
}

void print_info(Fitness** pary, int index)
{
	printf("회원 번호 : ");
	printf("%d\n", pary[index]->num);
	printf("회원 이름 : ");
	printf("%s\n", pary[index]->name);
	printf("회원 체중 : ");
	printf("%.2lf\n", pary[index]->weight);
}

void free_ary(Fitness** pary, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}

void main()
{
	Fitness* ary[100];
	int count = 0, index;
	int total = 0;
	double avgweight;

	printf("회원을 등록하세요.(번호가 음수일 경우 등록중단)\n");
	count = input_data(ary); // 등록한 회원수를 불러옴
	total += count; // 등록된 전체 회원 수
	printf("\n===================================\n");

	total_number(total);
	printf("\n===================================\n");

	avgweight = average_weight(ary, total);
	printf("평균 체중 : %.2lf", avgweight);
	printf("\n===================================\n");

	index = max_weight(ary, total); // 최대 체중 회원의 index
	print_info(ary, index); // 해당 index의 정보
	printf("\n===================================\n");

	free_ary(ary, total); //할당 해제
}