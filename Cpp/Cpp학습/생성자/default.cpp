#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class DHuman
{
private:
	char name[12];
	int age;

public:
	DHuman() {
		strcpy(name, "�̸�����");
		age = 0;
	}
	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

void sub03()
{
	DHuman momo;
	momo.intro();
}