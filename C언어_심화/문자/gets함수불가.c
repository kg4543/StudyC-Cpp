#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub11()
{
	printf("\n--------------\n");

	int age;
	char name[20];

	printf("나이 입력 : ");
	scanf("%d", &age);
	

	printf("이름 입력 : ");
	//gets(name);
	scanf("%s", name);
	printf("나이 : %d, 이름 : %s\n", age, name);

	// scanf - getchar() - gets()
	// printf - putchar() - puts()

	return 0;
}