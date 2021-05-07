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
		s1 = { 315, "아이유", 2.4 },
		s2 = { 316, "에일리", 3.7 },
		s3 = { 317, "이효리", 4.2 };

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

	printf("학번 : %d\n", max.id);
	printf("이름 : %s\n", max.name);
	printf("학점 : %.1lf\n", max.grade);

	return 0;
}