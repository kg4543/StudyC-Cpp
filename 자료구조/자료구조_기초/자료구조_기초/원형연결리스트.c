#include <stdio.h>

typedef struct listnode {
	int data;
	struct  listnode* link;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* cHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}

ListNode* cListNode(HeadNode* h, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패!!!");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	ListNode* curr = phead->head;
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = phead->head->link;
		while (curr != phead->head)
		{
			curr = curr->link;
		}
		curr->link = newNode;
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
}


void printNodeFirst(HeadNode* phead)
{
	ListNode* curr = phead->head;
	int i = 1;
	if (phead->head == NULL)
	{
		printf("연결된 노드가 없습니다.\n");
	}
	else
	{
		do
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("현재 주소: %u / 다음 주소: %u\n", curr, curr->link);
			curr = curr->link;
			i++;
		} while (curr != phead->head);
	}
}

void printNodeLast(HeadNode* phead)
{
	ListNode* curr = phead->head;
	int i = 1;
	if (phead->head == NULL)
	{
		printf("연결된 노드가 없습니다.\n");
	}
	else
	{
		do
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->link->data);
			printf("현재 주소: %u / 다음 주소: %u\n", curr->link, curr->link->link);
			curr = curr->link;
			i++;
		} while (curr != phead->head);
	}
}


void sub16()
{
	HeadNode* h = cHeadNode();
	ListNode* node1 = cListNode(h, 10);
	ListNode* node2 = cListNode(h, 20);
	ListNode* node3 = cListNode(h, 30);
	ListNode* node4 = cListNode(h, 40);
	ListNode* node5 = cListNode(h, 50);
	ListNode* node6 = cListNode(h, 60);
	insertFirstNode(h, node1);
	insertFirstNode(h, node2);
	insertFirstNode(h, node3);
	insertLastNode(h, node4);
	insertLastNode(h, node5);
	insertFirstNode(h, node6);

	printNodeFirst(h);
	//printNodeLast(h);

	return;
}