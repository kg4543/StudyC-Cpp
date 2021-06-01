#include <stdio.h>

class Human
{
public:
	char name[12];
	int age;

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

void sub04()
{
	Human arFriend[10] = {
		{"문동욱", 49},
		{"김유진", 49},
		{"박상막", 49}
	};

	Human* pFriend;
	pFriend = &arFriend[2];
	pFriend->intro();
}