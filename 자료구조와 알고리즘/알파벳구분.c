#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int* pary, int size);

void main()
{
	char input_ary[10]; // ���Ĺ� �Է�
	char* lower_ary, * upper_ary; // ��ҹ��� ����� ������
	upper_ary = (char*)malloc(sizeof(char)); //�빮�� ����� �Ҵ�
	lower_ary = (char*)malloc(sizeof(char)); //�ҹ��� ����� �Ҵ�

	int i = 0, j = 0, k = 0;
	printf("���Ĺ��� �Է��ϼ��� : ");
	for ( i = 0; i < 10; i++)
	{
		scanf(" %c", &input_ary[i]); // ���Ĺ� 10�� �Է�
	}

	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]); //�Է��� ���Ĺ� ���
	}

	int size = sizeof(input_ary) / sizeof(char);
	insertionSort(input_ary, size); // ���Ĺ� ��������
	
	printf("\n���� ��...\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]); //���� �� ���Ĺ� ���
	}

	for ( i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90) // �빮�� ã��
		{
			upper_ary[j] = input_ary[i]; //�빮�� ����ҿ� ����
			j++;
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122) //�ҹ��� ã��
		{
			lower_ary[k] = input_ary[i]; //�ҹ��� ����ҿ� ����
			k++;
		}
		else
		{
			printf("���ĺ��� �ƴմϴ�.\n"); //�Է� �� ���� ó��
		}
	}
	
	printf("\n�빮�� : "); // �빮�ڰ� ���� ���
	if (j == 0)
	{
		printf("�빮�ڰ� �����ϴ�."); 
	}
	else
	{
		for (i = 0; i < j; i++) //�빮�� ��� , j = ��� Ƚ��
		{
			printf("%5c", upper_ary[i]);
		}
	}
	

	printf("\n�ҹ��� : "); 
	if (k == 0) //�ҹ��ڰ� ���� ���
	{
		printf("�ҹ��ڰ� �����ϴ�.");
	}
	else 
	{
		for (i = 0; i < k; i++) //�ҹ��� ���, k = ��� Ƚ��
		{
			printf("%5c", lower_ary[i]);
		}
	}
	
}

void insertionSort(char* pary, int size)
{
	int i, j;
	char temp;
	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--) //�� ��ġ���� 0������ �迭�� ���߸鼭 ��
		{
			if (pary[j] < pary[j - 1]) // ���� ���� ��� ���� �� 0���� ��ȯ
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}