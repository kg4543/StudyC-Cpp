#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	5명의 사원아이디,사원이름, 한달 급여를 입력받아 출력한 뒤
	급여 총액과 평균 급여액을 구하시오;
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
		printf("사번 : ");
		scanf("%d", &Emp[i].id);

		printf("이름 : ");
		getchar();
		gets(temp);
		Emp[i].name = (char*)malloc(strlen(temp) + 1); //Emp[i].name이 가리키고 있는 공간의 크기를 할당
		if (Emp[i].name != NULL)
		{
			strcpy(Emp[i].name, temp);
		}
		
		printf("급여 : ");
		scanf("%d", &Emp[i].salary);
		sum += Emp[i].salary;
	}
	avg = sum / 5.0;

	for ( i = 0; i < 5; i++)
	{
		printf("\n--------------\n");
		printf("사번 : %d\n", Emp[i].id);
		printf("이름 : %s\n", Emp[i].name);
		printf("급여 : %d\n", Emp[i].salary);

		free(Emp[i].name);
	}

	printf("\n--------------\n");
	printf("급여 총액 : %u  급여 평균 : %u \n", sum, avg);

	return 0;
}