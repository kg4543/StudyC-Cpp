#include <stdio.h>

typedef struct node {
	int data;
	struct  node* next;
}Node;

typedef struct {
	Node* head;  // 노드를 가리킬 수 있는 타입
}HeadNode;

/* head를 생성하는 함수*/
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}

/* 전위 삽입 함수*/
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

/* 후위 삽입 함수*/
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
		printf("연결된 노드가 없습니다.\n");
	}
	else
	{
		Node* curr = h->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
	}
}

// 노드 검색
searchNode(HeadNode* h, int data)
{
	Node* curr = h->head;
	int i = 1, j = 0;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			j++;
		}
		curr = curr->next;
		i++;
	}
	if (j == 0)
	{
		printf("검색한 데이터가 없습니다.");
	}
}

// 검색 노드 삭제
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
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("삭제하시겠습니까?(Y/N)");
			scanf("%c", &c);
			if (c == 'Y' || c == 'y')
			{
				if (h->head->data == data) // head의 값을 삭제할 경우 head를 다음 위치로 변경
				{
					h->head = curr->next;
				}

				printf("삭제하였습니다.\n");
				temp->next = curr->next;
				free(curr);
				curr = temp->next;
				
				//h->head = curr;
				j++;
				continue;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("삭제를 취소하였습니다.\n");
				temp = curr;
				j++;
			}
			else
			{
				printf("인식할 수 없습니다. 명령을 취소합니다.\n");
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
		printf("데이터가 없습니다.");
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
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			printf("뒤에 추가하시겠습니까?(Y/N)");
			scanf("%c", &c);
			getchar();
			if (c == 'Y' || c == 'y')
			{
				printf("추가할 데이터 : ");
				scanf("%d", &p);
				Node* new = (Node*)malloc(sizeof(Node));
				new->data = p;
				new->next = curr->next;
				curr->next = new;
				return;
			}
			else if (c == 'N' || c == 'n')
			{
				printf("추가를 취소하였습니다.\n");
				j++;
			}
			else
			{
				printf("인식할 수 없습니다. 명령을 취소합니다.\n");
				j++;
				break;
			}
		}
		curr = curr->next;
	}
	if (j == 0)
	{
		printf("검색한 데이터가 없습니다.");
	}
}

int sub14()
{
	HeadNode* h = createHead();
	int a;

	printf("\n-----------------\n");
	// 입력
	rearinsertNode(h, 10);
	rearinsertNode(h, 10);
	rearinsertNode(h, 30);
	rearinsertNode(h, 40);
	rearinsertNode(h, 50);
	rearinsertNode(h, 30);
	//출력
	printNode(h);
	printf("\n-----------------\n");

	//삭제
	//DeleteNode(h);

	//검색
	//searchNode(h, 30);
	//printf("\n-----------------\n");

	//선택 삭제
	printf("삭제할 값 : ");
	scanf("%d", &a);
	searchDelNode(h, a);

	//선택 삽입
	/*printf("검색할 값 : ");
	scanf("%d", &a);
	midInsertNode(h, a);*/

	printf("\n-----------------\n");
	printNode(h);
	

	return 0;
}