#include <stdio.h>
#include <stdbool.h>

#define SIZE 6

int isqEmpty();
int isqFull();
void enQueue(int);  //Queue에서 삽입
int deQueue();  //Queue에서 제거

int rear = 0;  //입구
int front = 0;  //출구

int queue[SIZE];

void sub19()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);

	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());

	return;
}

int isqEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}

int isqFull()
{
	if (front == (rear + 1) % SIZE)
		return true;
	else
		return false;
}

void enQueue(int data)
{
	if (isqFull())
	{
		printf("Queue overflow!!\n");
	}
	else
	{
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}

int deQueue()
{
	if (isqEmpty())
	{
		printf("Queue underflow!!\n");
		//return;
		exit(1);
	}
	else
	{
		return queue[front++ % SIZE];
	}
}