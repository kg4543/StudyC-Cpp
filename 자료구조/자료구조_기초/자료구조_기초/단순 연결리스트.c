#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node	
{
	int data; // data �ɹ�
	struct node* link; // ���� ����� �ּҸ� ������ �ɹ�
}Node;

Node* addNode(Node* target, int data);

int sub13()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;
	/*Node* node1 = addNode(head, 10);
	Node* node2 = addNode(node1, 20);
	Node* node3 = addNode(node2, 30);
	Node* node4 = addNode(node3, 40);
	Node* node5 = addNode(node4, 50);*/
	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	addNode(head, 50);

	Node* curr = head->link;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d��° ��� ������ %d\n",i, curr->data);
		curr = curr->link;
		i++;
	}

	Node* temp;
	curr = head->link;
	while (curr != NULL)
	{
		temp = curr->link;
		free(curr);
		curr = temp;
	}

	free(head);

	return 0;
}

/*���� ��带 ����, ��带 ��������
�Է��� ����� ���������� ���ο� ��尡 �ް�
�Է��� ���� ���� ������ ��带 ����Ų��.*/

Node* addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
	//newNode->link = NULL;

	return newNode;
}

/*Node* node1 = (Node*)malloc(sizeof(Node));  //��� ����
	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1; //�����忡 ù��° ����� �ּҰ��� �ش�.

	Node* node2 = (Node*)malloc(sizeof(Node));
	if (node2 == NULL) return;
	node2->data = 20;
	node1->link = node2;

	Node* node3 = (Node*)malloc(sizeof(Node));
	if (node3 == NULL) return;
	node3->data = 30;
	node2->link = node3;
	node3->link = NULL;*/