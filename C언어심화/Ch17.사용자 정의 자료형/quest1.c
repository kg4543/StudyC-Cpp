#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	5���� ������̵�,����̸�, �Ѵ� �޿��� �Է¹޾� ����� ��
	�޿� �Ѿװ� ��� �޿����� ���Ͻÿ�;
*/

typedef struct employee {
	int id;
	char* name;
	int salary;
}Employee;


int question1() {

	printf("\n--------------\n");

	struct employee Emp[5];

	int sum = 0;
	int avg = 0;
	char temp[20];
	int i;

	for ( i = 0; i < 5; i++)
	{
		printf("��� : ");
		scanf("%d", &Emp[i].id);

		printf("�̸� : ");
		getchar();
		gets(temp);
		Emp[i].name = (char*)malloc(strlen(temp) + 1); //Emp[i].name�� ����Ű�� �ִ� ������ ũ�⸦ �Ҵ�
		if (Emp[i].name != NULL)
		{
			strcpy(Emp[i].name, temp);
		}
		
		printf("�޿� : ");
		scanf("%d", &Emp[i].salary);
		sum += Emp[i].salary;
	}
	avg = sum / 5.0;

	for ( i = 0; i < 5; i++)
	{
		printf("\n--------------\n");
		printf("��� : %d\n", Emp[i].id);
		printf("�̸� : %s\n", Emp[i].name);
		printf("�޿� : %d\n", Emp[i].salary);

		free(Emp[i].name);
	}

	printf("\n--------------\n");
	printf("�޿� �Ѿ� : %u  �޿� ��� : %u \n", sum, avg);

	return 0;
}