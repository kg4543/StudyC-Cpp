#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	char* pname;

	double weight;
}Fitness;

int input_data(Fitness** pary, int total)
{
	int i = total; // ��ü �ɹ� �� ���ĺ��� �ٽ� ���
	while (1)
	{
		pary[i] = (Fitness*)malloc(sizeof(Fitness)); // ȸ�� ������ ����� �� ���� �����Ҵ�
		printf("ȸ�� ��ȣ : ");
		scanf("%d", &pary[i]->num); // ������ ��� Ż��
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

	return i - total; // �̹��� ����� ȸ������ ����
}

void total_number(int count)
{
	printf("��ü ȸ�� �� : %d ��\n", count); // ��ü ȸ������ �޾ƿ� ���
}

double average_weight(Fitness** pary, int count) // ȸ�� ����ŭ �ݺ��ؼ� ��� ���� ���ϱ�
{
	if (count == 0)
	{
		printf("��ϵ� ȸ���� �����ϴ�.\n");
		return 0;
	}

	double sum_weight = 0;
	double avg_weight = 0;

	for (int i = 0; i < count; i++)
	{
		sum_weight += pary[i]->weight;
	}
	avg_weight = sum_weight / count;

	return avg_weight;
}

int max_weight(Fitness** pary, int count) // ȸ�� ����ŭ �ݺ��ؼ� �ִ� ���� �� index ã��
{
	if (count == 0)
	{
		return -1;
	}

	double max_weight = 0;
	for (int i = 0; i < count; i++)
	{
		if (max_weight < pary[i]->weight) // �ִ� ü�� ã��
		{
			max_weight = pary[i]->weight;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (max_weight == pary[i]->weight)
		{
			return i; // // �ִ� ü�߿� �´� index�� ����
		}
	}
}

int search_info(Fitness** pary, int count, int s) // 's' �˻��� ȸ����ȣ�� �´� index ã��
{
	for (int i = 0; i < count; i++)
	{
		if (s == pary[i]->num)
		{
			return i; // ȸ�� ��ȣ�� �´� index�� ����
		}
	}
	return -1; //�˻��� ȸ���� ���� ��� -1 ����
}

void print_info(Fitness** pary, int index) // index ��ȣ�� �´� ȸ�� ���� ���
{
	if (index == -1) // -1�� ȸ���� ���� ���
	{
		printf("��ϵ� ȸ���� �����ϴ�.\n");
	}
	else
	{
		printf("ȸ�� ��ȣ : ");
		printf("%d\n", pary[index]->num);
		printf("ȸ�� �̸� : ");
		printf("%s\n", pary[index]->name);
		printf("ȸ�� ü�� : ");
		printf("%.2lf\n", pary[index]->weight);
	}
}

void free_ary(Fitness** pary, int count) // �����ϸ鼭 �����Ҵ� ����
{
	for (int i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}

void main()
{
	Fitness* ary[100];
	int choice = 0; // �޴� ����
	int infi = 1; // �޴� �ݺ�
	int count = 0, total = 0;  // ȸ�� ��
	int index; // ȸ�� ���� �迭 index
	int search; //�˻��� ȸ����ȣ
	double avgweight; // ȸ�� ��չ���

	while (infi)
	{
		printf("=================================================================\n");
		printf("1. ȸ�� ��� 2. �ο� �� 3. �˻� 4. ��� ü�� 5. �ִ� ü�� 6.����\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("ȸ���� ����ϼ���.(��ȣ�� ������ ��� ����ߴ�)\n");
			printf("=================================================================\n");
			count = input_data(ary, total); // ����� ȸ������ �ҷ���
			total += count; // ���� ȸ�� �� + ����� ȸ�� ��
			break;
		case 2:
			printf("=================================================================\n");
			total_number(total);
			break;
		case 3:
			printf("=================================================================\n");
			printf("�˻��� ȸ�� ��ȣ : ");
			scanf("%d", &search);
			index = search_info(ary, total, search);
			print_info(ary, index); // �ش� index�� ȸ�� ����
			break;
		case 4:
			printf("=================================================================\n");
			avgweight = average_weight(ary, total);
			printf("��� ü�� : %.2lf\n", avgweight);
			break;
		case 5:
			printf("=================================================================\n");
			index = max_weight(ary, total); // �ִ� ü�� ȸ���� index
			print_info(ary, index); // �ش� index�� ȸ�� ����
			break;
		case 6:
			free_ary(ary, total); //�Ҵ� ����
			infi = 0;
			printf("\n������ �����մϴ�.\n");
			break;
		default:
			printf("\n�Է��� �� �� �Ǿ����ϴ�. ������ �����մϴ�.\n");
			infi = 0;
			break;
		}
	}
}