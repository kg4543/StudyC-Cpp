#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub5()
{
	printf("\n--------------\n");

	int num, grade;

	printf("�й� �Է� : ");
	scanf("%d",&num);
	getchar();
	printf("���� �Է� : ");
	grade = getchar();
	// 10 '����' A '����'
	// getchar()�� '����'�� ���������� ������ A�� �ƴ� '����' ���ڸ� �а� �ȴ�.

	printf("�й� : %d,���� : %c",num, grade);

	return 0;
}