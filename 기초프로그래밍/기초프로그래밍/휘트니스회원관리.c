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
		printf("ȸ�� ��ȣ : ");
		scanf("%d", &pary[i]->num);
		if (pary[i]->num < 0)
		{
			free(pary[i]);
			break;
		}
		printf("ȸ�� �̸� : ");
		scanf("%s", &pary[i]->name);
		printf("ȸ�� ü�� : ");
		scanf("%lf", &pary[i]->weight);
		i++;
	}

	return i; // 0���� �����Ͽ� -1�� �� �ʿ䰡 ����.
}

void total_number(int count)
{
	printf("��ü ȸ�� �� : %d ��", count);
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
	printf("ȸ�� ��ȣ : ");
	printf("%d\n", pary[index]->num);
	printf("ȸ�� �̸� : ");
	printf("%s\n", pary[index]->name);
	printf("ȸ�� ü�� : ");
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

	printf("ȸ���� ����ϼ���.(��ȣ�� ������ ��� ����ߴ�)\n");
	count = input_data(ary); // ����� ȸ������ �ҷ���
	total += count; // ��ϵ� ��ü ȸ�� ��
	printf("\n===================================\n");

	total_number(total);
	printf("\n===================================\n");

	avgweight = average_weight(ary, total);
	printf("��� ü�� : %.2lf", avgweight);
	printf("\n===================================\n");

	index = max_weight(ary, total); // �ִ� ü�� ȸ���� index
	print_info(ary, index); // �ش� index�� ����
	printf("\n===================================\n");

	free_ary(ary, total); //�Ҵ� ����
}