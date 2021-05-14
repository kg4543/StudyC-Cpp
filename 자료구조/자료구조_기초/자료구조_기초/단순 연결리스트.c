#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node	
{
	int data; // data 맴버
	struct node* link; // 다음 노드의 주소를 저장할 맴버
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
		printf("%d번째 노드 데이터 %d\n",i, curr->data);
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

/*연결 노드를 생성, 노드를 생성시켜
입력한 노드의 원래연결을 새로운 노드가 받고
입력한 노드는 새로 생성한 노드를 가리킨다.*/

Node* addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
	//newNode->link = NULL;

	return newNode;
}

/*Node* node1 = (Node*)malloc(sizeof(Node));  //노드 생성
	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1; //헤더노드에 첫번째 노드의 주소값을 준다.

	Node* node2 = (Node*)malloc(sizeof(Node));
	if (node2 == NULL) return;
	node2->data = 20;
	node1->link = node2;

	Node* node3 = (Node*)malloc(sizeof(Node));
	if (node3 == NULL) return;
	node3->data = 30;
	node2->link = node3;
	node3->link = NULL;*/