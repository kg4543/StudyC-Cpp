#include <stdio.h>

int sub2()
{
	enum origin {EAST, WEST, SOUTH, NORTH};
	enum origin mark = WEST;
	printf("%d 방향 \n", mark);

	typedef struct
	{
		char name[12];
		int age;
		double height;
	}SHuman;

	SHuman kim = { "김상형", 29, 181.4 };
	printf("이름 = %s, 나이 = %d\n", kim.name, kim.age);

	return 0;
}