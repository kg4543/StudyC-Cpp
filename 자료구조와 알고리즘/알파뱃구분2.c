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
		h->head = new;
	}
	else
	{
		Alpha* curr = h->head;
		while (curr->link != NULL)
		{
			curr = curr->link;
		}
		curr->link = new;
	}
}

void printAlpha(Head* h)
{
	Alpha* curr = h->head;
	while (curr != NULL)
	{
		printf("%5c", curr -> ch);
		curr = curr -> link;
	}
}

void insertionSort2(char* pary, int size)
{
	int i, j;
	char temp;
	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--) //각 위치에서 0번까지 배열을 낮추면서 비교
		{
			if (pary[j] < pary[j - 1]) // 값이 작을 경우 앞으로 이동
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}

void mai()
{
	char input_ary[10];
	Head* Uhead = createHead();
	Head* Lhead = createHead();

	int i = 0, j = 0, k = 0;
	printf("알파뱃을 입력하세요 : ");
	for (i = 0; i < 10; i++)
	{
		scanf(" %c ", &input_ary[i]);
	}

	int size = sizeof(input_ary) / sizeof(char);
	insertionSort(input_ary, size);

	for (i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90)
		{
			createNode(Uhead, input_ary[i]);
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122)
		{
			createNode(Lhead, input_ary[i]);
		}
		else
		{
			printf("알파벳이 아닙니다.\n");
		}
	}

	printf("\n대문자 : ");
	printAlpha(Uhead);
	printf("\n소문자 : ");
	printAlpha(Lhead);
}