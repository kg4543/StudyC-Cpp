#include <stdio.h>

/*
default ��
����ü : public
Ŭ���� : private
*/

struct SAHuman
{
int age;

private:
	char name[12];

public:
	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

void sub03()
{
	SAHuman kim;
	//kim.name = "kim";
	kim.age = 28;
	kim.intro();
}