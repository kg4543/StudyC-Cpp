#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char ch;
	struct Alpha* link;
}Alpha;

typedef struct {
	Alpha* head;
}Head;

Head* createHead()
{
	Head* h = (Head*)malloc(sizeof(Head));
	h->head = NULL;
	return h;
}

void createNode(Head* h, char c)
{
	Alpha* new = (Alpha*)malloc(sizeof(Alpha));
	new->ch = c;
	new->link = NULL;
	
	if (h->head == NULL)
	{
		h->head = new; // head�� ���� ��� ����带 head�� ����
	}
	else
	{
		Alpha* curr = h->head;
		while (curr->link != NULL) //������������ �ݺ�
		{
			curr = curr->link;
		}
		curr->link = new; // ������ ��� ������ ������ ����
	}
}

void printAlpha(Head* h)
{
	Alpha* curr = h->head;
	while (curr != NULL) //������ ������ �ݺ�
	{
		printf("%5c", curr -> ch); //��� ���
		curr = curr -> link; // ���� ����
	}
}

void insertionSort2(char* pary, int size)
{
	int i, j;
	char temp;
	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--) //�� ��ġ���� 0������ �迭�� ���߸鼭 ��
		{
			if (pary[j] < pary[j - 1]) // ���� ���� ��� ������ �̵�
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}

void sub()
{
	char input_ary[10]; // �Է� �迭
	Head* Uhead = createHead(); // �빮�� ���� ����Ʈ
	Head* Lhead = createHead(); // �ҹ��� ���� ����Ʈ

	int i = 0, j = 0, k = 0;
	printf("���Ĺ��� �Է��ϼ��� : ");
	for (i = 0; i < 10; i++)
	{
		scanf(" %c ", &input_ary[i]);
	}

	int size = sizeof(input_ary) / sizeof(char);
	insertionSort(input_ary, size);

	for (i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90) // �빮�� ã��
		{
			createNode(Uhead, input_ary[i]); // �빮�� ���Ḯ��Ʈ ��� ����
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122) // �ҹ��� ã��
		{
			createNode(Lhead, input_ary[i]); // �ҹ��� ���Ḯ��Ʈ ��� ����
		}
		else
		{
			printf("���ĺ��� �ƴմϴ�.\n"); // �Է°� ����ó��
		}
	}

	printf("\n�빮�� : ");
	printAlpha(Uhead); // �빮�� ���Ḯ��Ʈ ���
	printf("\n�ҹ��� : ");
	printAlpha(Lhead); // �ҹ��� ���Ḯ��Ʈ ���
}