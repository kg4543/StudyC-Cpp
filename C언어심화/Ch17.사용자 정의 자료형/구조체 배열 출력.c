#include <stdio.h>

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

void print_list(struct address* lp);

int sub7()
{
	printf("\n--------------\n");

	struct address list[5] = {
		{"������",23,"111-1111","�︪�� ����"},
		{"�����",57,"222-2222","���� ��õ��"},
		{"���ϸ�",32,"333-3333","�ϵ� û����"},
		{"��ȿ��",42,"444-4444","���� ������"},
		{"����ȿ",40,"555-5555","Ȳ�ص� ����"}
	};

	print_list(list);

	return 0;
}

void print_list(struct address* lp)
{
	int i;

	for ( i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			(lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr);
	}
}