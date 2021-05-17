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
		printf("메모리 할당 실패");
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
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("이전 주소: %u / 현재 주소: %u / 다음 주소: %u\n", curr->prev, curr, curr->next);
			j++;
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("데이터가 없습니다.");
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
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("이전 주소: %u / 현재 주소: %u / 다음 주소: %u\n", curr->prev, curr, curr->next);
			printf("삭제하시겠습니까?(Y/N)");
			scanf("%c", &c);
			if (c=='Y' || c=='y')
			{
				if (phead->head->data == data) // 처음 노드 삭제
				{
					phead->head = curr->next;
					curr->next->prev = NULL;
				}
				else if (curr->next == NULL) //마지막 노드 삭제
				{
					curr->prev->next = NULL;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}
				
				free(curr);
				printf("삭제하였습니다.\n");
				return;
				j++;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("삭제를 취소하였습니다.\n");
				j++;
			}
			else
			{
				printf("인식할 수 없습니다. 명령을 취소합니다.\n");
				return;
				j++;
			}
			getchar();
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("데이터가 없습니다.");
	}
}

void printallNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("연결된 노드가 없습니다.\n");
	}
	else
	{
		DListNode* curr = phead->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("이전 주소: %u / 현재 주소: %u / 다음 주소: %u\n", curr->prev, curr, curr->next);
			curr = curr->next;
			i++;
		}
	}
}

void sub15()
{
	int a;
	// 생성&연결
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

	/*printf("검색할 값 : ");
	scanf("%d", &a);
	findNode(phead, a);

	printf("\n===============================\n");*/

	// 전체삭제
	//delallNode(phead);
	 
	// 선택삭제
	printf("삭제할 값 : ");
	scanf("%d", &a);
	delNode(phead, a);

	printf("\n===============================\n");

	printallNode(phead);
}