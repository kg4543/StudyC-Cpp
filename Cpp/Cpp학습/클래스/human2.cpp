#include <stdio.h>

struct SHuman
{
	char name[12];
	int age;
	void intro();
	
};

void SHuman::intro()
{
	printf("�̸� = %s, ���� = %d\n", name, age);
}

void sub02()
{
	SHuman kim = { "�����" , 29 };
	kim.intro();
}