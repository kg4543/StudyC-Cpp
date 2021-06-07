#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage)
	{
		strcpy(name, aname);
		age = aage;
	}
	virtual void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student : public Human
{
private:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void intro()
	{
		printf("%d�й��Դϴ�.\n", stunum, name);
	}
	virtual void study()
	{
		printf("���̴� ��,�̻��� ��,�̻� ��\n");
	}
};

void IntroSomeBody(Human* pH)
{
	pH->intro();
}

void sub06()
{
	Human h("Mario", 10);
	Student s("Luizi", 15, 1234567);

	IntroSomeBody(&h);
	IntroSomeBody(&s);
}