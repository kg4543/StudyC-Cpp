#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub11()
{
	printf("\n--------------\n");

	int age;
	char name[20];

	printf("���� �Է� : ");
	scanf("%d", &age);
	

	printf("�̸� �Է� : ");
	//gets(name);
	scanf("%s", name);
	printf("���� : %d, �̸� : %s\n", age, name);

	// scanf - getchar() - gets()
	// printf - putchar() - puts()

	return 0;
}