#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vision
{
	double left;
	double right;
};

struct vision exchange(struct vision robot);  // �� �÷��� �ٲٴ� �Լ�

int sub4()
{
	printf("\n--------------\n");

	struct vision robot;

	printf("�÷� �Է� : ");

	scanf("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);

	printf("�ٲ� �÷� : %.1lf  %.1lf\n", robot.left, robot.right);

	return 0;
}

struct vision exchange(struct vision robot)
{
	double temp;

	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;
};