#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub5()
{
	printf("\n--------------\n");

	int num, grade;

	printf("학번 입력 : ");
	scanf("%d",&num);
	getchar();
	printf("학점 입력 : ");
	grade = getchar();
	// 10 '개행' A '개행'
	// getchar()로 '개행'을 날려버리지 않으면 A가 아닌 '개행' 문자를 읽게 된다.

	printf("학번 : %d,학점 : %c",num, grade);

	return 0;
}