#include <stdio.h>
#include <stdbool.h>

typedef struct snode {
	int data;
	struct snode* link;
}SNode;

typedef struct tstack {
	SNode* topstk;
}TStack;

TStack* createHead2()
{
	TStack* t = (TStack*)malloc(sizeof(TStack));
	if (t != NULL)
		t->topstk = NULL;
	return t;
}

int isEmpty2(TStack* ptstack)
{
	if (ptstack->topstk == NULL)
		return true;
	else
		return false;
}

void push2(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL)
		return;
	newNode->data = data;
	newNode->link = ptstack->topstk;
	ptstack->topstk = newNode;
}

int pop2(TStack* ptstack)
{
	int data;
	SNode* temp;
	if (isEmpty(ptstack))
	{
		printf("STACK is Empty!!!\n");
		return;
	}
	else
	{
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;
		free(temp);
		return data;
	}
}

int peek2(TStack* ptstack)
{
	if (isEmpty(ptstack))
	{
		printf("STACK EMPTY!!\n");
		return;
	}
	else
	{
		return ptstack->topstk->data;
	}
}

void printStack2(TStack* ptstack)
{
	SNode* curr = ptstack->topstk;
	while (curr != NULL)
	{
		printf("%5d", curr->data);
		curr = curr->link;
	}
}

void sub18()
{
	TStack* h = createHead();
	push2(h, 10);
	push2(h, 20);
	push2(h, 30);
	push2(h, 40);

	printStack2(h);
	pop2(h);
	printStack2(h);

	return;
}