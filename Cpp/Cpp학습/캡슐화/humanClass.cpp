#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) // const
	{
		printf("����\n");
		strcpy(name, aname);
		if (aage >=0 && aage <= 120)
		{
			age = aage;
		}
		else
		{
			age = 0;
		}
	}
	~Human()
	{
		printf("�Ҹ�\n");
	}

	void outinfo()
	{
		printf("�̸�: %s, ����: %d\n", name, age);
	}
};

void sub03()
{
	Human man1("Kim", 21);
	man1.outinfo();
}
