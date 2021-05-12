#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct list {
	int num;
	struct list* next;
};

int sub8() {

	printf("\n--------------\n");

	struct list a = { 10,0 }, b = { 20,0 }, c = { 30,0 };
	struct list* head = &a, * current;

	a.next = &b;
	b.next = &c;

	//head -> a | next -> b | next -> c | 0
	//current = current -> next

	printf("head->num : %d\n", head->num);
	printf("head->next->num : %d\n", head->num);

	printf("list all : ");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;
}