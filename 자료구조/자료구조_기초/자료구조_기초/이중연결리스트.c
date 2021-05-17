#include <stdio.h>

typedef struct dlistnode
{
	int data;
	struct dlistnode* next;
	struct dlistnode* prev;
}DListNode;

typedef struct {
	DListNode* head;
}HeadNode;

HeadNode* createHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}

	return h;
}

DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

void linkNode(HeadNode* phead, DListNode* prevNode, DListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		prevNode = phead;
	}
	else
	{
		if (prevNode->next != NULL)
		{
			newNode->next = prevNode->next;
			prevNode->next->prev = newNode;
		}
		prevNode->next = newNode;
		newNode->prev = prevNode;
	}
}

void findNode(HeadNode* phead, int data)
{
	DListNode* curr = phead->head;

	int i = 0, j = 0;
	char c;

	getchar();
	while (curr != NULL)
	{
		i++;

		if (curr->data == data)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			printf("���� �ּ�: %u / ���� �ּ�: %u / ���� �ּ�: %u\n", curr->prev, curr, curr->next);
			j++;
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("�����Ͱ� �����ϴ�.");
	}
}


void delallNode(HeadNode* phead)
{
	DListNode* curr = phead->head;
	DListNode* temp;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	phead->head = NULL;
}

void delNode(HeadNode* phead, int data)
{
	DListNode* curr = phead->head;

	int i = 0, j = 0;
	char c;

	getchar();
	while (curr != NULL)
	{
		i++;
		
		if (curr->data == data)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			printf("���� �ּ�: %u / ���� �ּ�: %u / ���� �ּ�: %u\n", curr->prev, curr, curr->next);
			printf("�����Ͻðڽ��ϱ�?(Y/N)");
			scanf("%c", &c);
			if (c=='Y' || c=='y')
			{
				if (phead->head->data == data) // ó�� ��� ����
				{
					phead->head = curr->next;
					curr->next->prev = NULL;
				}
				else if (curr->next == NULL) //������ ��� ����
				{
					curr->prev->next = NULL;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}
				
				free(curr);
				printf("�����Ͽ����ϴ�.\n");
				return;
				j++;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("������ ����Ͽ����ϴ�.\n");
				j++;
			}
			else
			{
				printf("�ν��� �� �����ϴ�. ����� ����մϴ�.\n");
				return;
				j++;
			}
			getchar();
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("�����Ͱ� �����ϴ�.");
	}
}

void printallNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("����� ��尡 �����ϴ�.\n");
	}
	else
	{
		DListNode* curr = phead->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			printf("���� �ּ�: %u / ���� �ּ�: %u / ���� �ּ�: %u\n", curr->prev, curr, curr->next);
			curr = curr->next;
			i++;
		}
	}
}

void sub15()
{
	int a;
	// ����&����
	HeadNode* phead = createHeadNode();
	DListNode* Node1 = createNode(10);
	DListNode* Node2 = createNode(20);
	DListNode* Node3 = createNode(30);
	DListNode* Node4 = createNode(30);
	linkNode(phead, NULL, Node1);
	linkNode(phead, Node1, Node2);
	linkNode(phead, Node1, Node3);
	linkNode(phead, Node2, Node4);
	printallNode(phead);

	printf("\n===============================\n");

	/*printf("�˻��� �� : ");
	scanf("%d", &a);
	findNode(phead, a);

	printf("\n===============================\n");*/

	// ��ü����
	//delallNode(phead);
	 
	// ���û���
	printf("������ �� : ");
	scanf("%d", &a);
	delNode(phead, a);

	printf("\n===============================\n");

	printallNode(phead);
}