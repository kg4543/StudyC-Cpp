#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int id;
	char name[20];
	double grade;
};

int sub3()
{
	printf("\n--------------\n");

	struct student 
		s1 = { 315, "������", 2.4 },
		s2 = { 316, "���ϸ�", 3.7 },
		s3 = { 317, "��ȿ��", 4.2 };

	struct student max;

	max = s1;
	if (s2.grade > max.grade)
	{
		max = s2;
	}
	if (s3.grade > max.grade)
	{
		max = s3;
	}

	printf("�й� : %d\n", max.id);
	printf("�̸� : %s\n", max.name);
	printf("���� : %.1lf\n", max.grade);

	return 0;
}