#include <stdio.h>

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

int sub6()
{
	printf("\n--------------\n");

	struct address list[5] = {
		{"아이유",23,"111-1111","울릉도 독도"},
		{"이재명",57,"222-2222","서울 건천동"},
		{"에일리",32,"333-3333","완도 청해진"},
		{"이효리",42,"444-4444","제주 서귀포"},
		{"송지효",40,"555-5555","황해도 해주"}
	};

	int i;

	for ( i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
	return 0;
}