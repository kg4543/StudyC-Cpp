#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void sub8()
{
	int i;
	struct employee Lee[5] =
	{
		{"����ȣ",2014,4200},
		{"���ѿ�",2015,3300},
		{"�̻��",2015,3500},
		{"�̻��",2016,2900}
	};
	struct employee* Sptr = Lee+4;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2015;
	Sptr->pay = 5900;
	
	printf("========================\n");
	for ( i = 0; i < 5; i++)
	{
		printf("�̸� : %s \n", Lee[i].name);
		printf("�Ի� : %d \n", Lee[i].year);
		printf("���� : %d \n", Lee[i].pay);
		printf("========================\n");
	}
	getchar();
}