#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* name, int age) {
		strcpy(this->name, name); // this. ��ü �ڽ�
		this->age = age;
	}
	void intro() {
		printf("�̸� = %s,���� = %d\n", name, age);
	}
};

void sub07()
{
	Human kim("�����", 29);
	kim.intro();
}