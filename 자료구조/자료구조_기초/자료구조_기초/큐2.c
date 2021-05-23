#include <stdio.h>
#include <stdbool.h>

#define SIZE 6

int queue[SIZE];

typedef struct qnode {
	int data;
	struct qnode* link;
}QNode;

typedef struct pqueue {
	QNode* front;
	QNode* rear;
}PQueue;

PQueue* createQHead()
{
	PQueue* f = (PQueue*)malloc(sizeof(PQueue));
	if (f != NULL)
	{
		f->front = NULL;
		f->rear = NULL;
		return f;
	}
	else
	{
		printf("메모리 할당 실패");
		return f;
	}
}

int isqEmpty2(PQueue* f)
{
	if (f->front == NULL && f->rear == NULL)
		return true;
	else
		return false;
}

int isqFull2(PQueue* f)
{
	return false;
}

void enQueue2(PQueue* f, int data)
{
	QNode* q = (QNode*)malloc(sizeof(QNode));
	q->data = data;

	if (isqFull2(f))
	{
		printf("Queue overflow!!\n");
	}
	else if (isqEmpty(f))
	{
		f->rear = q;
		f->front = q;
		q->link = NULL;
	}
	else
	{
		q->link = f->rear;
		f->rear = q;
	}
}


QNode* deQueue2(PQueue* f)
{

	if (isqEmpty(f))
	{
		printf("Queue underflow!!\n");
	}
	else
	{
		QNode* front = f->front;
		QNode* curr = f->rear;
		while (curr == f->rear)
		{
			curr = curr->link;
		}
		f->front = curr;
		return front->data;
	}
}


void sub20()
{
	PQueue* q = createQHead();

	enQueue2(q, 10);
	enQueue2(q, 20);
	enQueue2(q, 30);

	printf("%5d\n", deQueue2(q));
	printf("%5d\n", deQueue2(q));
	printf("%5d\n", deQueue2(q));

	return;
}