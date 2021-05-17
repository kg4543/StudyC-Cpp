#include <stdio.h>

typedef struct node {
	int data;
	struct  node* next;
}Node;

typedef struct {
	Node* head;  // ��带 ����ų �� �ִ� Ÿ��
}HeadNode;

/* head�� �����ϴ� �Լ�*/
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}

/* ���� ���� �Լ�*/
preinsertNode(HeadNode* h,int data) 
{
	Node* new = (Node*)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		new->next = h->head;
		h->head = new;
	}
}

/* ���� ���� �Լ�*/
rearinsertNode(HeadNode* h, int data)
{
	Node* new = (Node*)malloc(sizeof(Node));

	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
		if (h->head == NULL)
		{
			h->head = new;
		}
		else
		{
			Node* curr = h->head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = new;
		}
	}
}

DeleteNode(HeadNode* h)
{
		Node* temp;
		Node* curr = h->head;
		while (curr != NULL)
		{
			temp = curr->next;
			free(curr);
			curr = temp;
		}
		
		//free(h);
		h->head = NULL;
}

printNode(HeadNode* h)
{
	if (h->head== NULL)
	{
		printf("����� ��尡 �����ϴ�.\n");
	}
	else
	{
		Node* curr = h->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
	}
}

// ��� �˻�
searchNode(HeadNode* h, int data)
{
	Node* curr = h->head;
	int i = 1, j = 0;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			j++;
		}
		curr = curr->next;
		i++;
	}
	if (j == 0)
	{
		printf("�˻��� �����Ͱ� �����ϴ�.");
	}
}

// �˻� ��� ����
void searchDelNode(HeadNode* h, int data)
{
	Node* curr = h->head;
	Node* temp = h;
	int i = 0, j = 0;
	char c;
	getchar();

	
	while (curr != NULL)
	{
		i++;
		if (curr->data == data)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			printf("�����Ͻðڽ��ϱ�?(Y/N)");
			scanf("%c", &c);
			if (c == 'Y' || c == 'y')
			{
				if (h->head->data == data) // head�� ���� ������ ��� head�� ���� ��ġ�� ����
				{
					h->head = curr->next;
				}

				printf("�����Ͽ����ϴ�.\n");
				temp->next = curr->next;
				free(curr);
				curr = temp->next;
				
				//h->head = curr;
				j++;
				continue;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("������ ����Ͽ����ϴ�.\n");
				temp = curr;
				j++;
			}
			else
			{
				printf("�ν��� �� �����ϴ�. ����� ����մϴ�.\n");
				j++;
				break;
			}
			getchar();
		}
		else
		{
			temp = curr;
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("�����Ͱ� �����ϴ�.");
	}
}

void midInsertNode(HeadNode* h, int data)
{
	Node* curr = h->head;
	int i = 0, j = 0;
	char c;
	int p;
	getchar();

	while (curr != NULL)
	{
		i++;
		if (curr->data == data)
		{
			printf("%d��° ��� ������ %d\n", i, curr->data);
			printf("�ڿ� �߰��Ͻðڽ��ϱ�?(Y/N)");
			scanf("%c", &c);
			getchar();
			if (c == 'Y' || c == 'y')
			{
				printf("�߰��� ������ : ");
				scanf("%d", &p);
				Node* new = (Node*)malloc(sizeof(Node));
				new->data = p;
				new->next = curr->next;
				curr->next = new;
				return;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("�߰��� ����Ͽ����ϴ�.\n");
				j++;
			}
			else
			{
				printf("�ν��� �� �����ϴ�. ����� ����մϴ�.\n");
				j++;
				break;
			}
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("�˻��� �����Ͱ� �����ϴ�.");
	}
}

int sub14()
{
	HeadNode* h = createHead();
	int a;

	printf("\n-----------------\n");
	// �Է�
	rearinsertNode(h, 10);
	rearinsertNode(h, 10);
	rearinsertNode(h, 30);
	rearinsertNode(h, 40);
	rearinsertNode(h, 50);
	rearinsertNode(h, 30);
	//���
	printNode(h);
	printf("\n-----------------\n");

	//����
	//DeleteNode(h);

	//�˻�
	//searchNode(h, 30);
	//printf("\n-----------------\n");

	//���� ����
	printf("������ �� : ");
	scanf("%d", &a);
	searchDelNode(h, a);

	//���� ����
	/*printf("�˻��� �� : ");
	scanf("%d", &a);
	midInsertNode(h, a);*/

	printf("\n-----------------\n");
	printNode(h);
	

	return 0;
}