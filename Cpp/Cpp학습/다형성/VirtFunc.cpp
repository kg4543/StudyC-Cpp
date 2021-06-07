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
		printf("이름 = %s,  나이 = %d\n",name,age);
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
	virtual void intro()
	{
		printf("%d학번입니다.\n", stunum);
	}
	void study()
	{
		printf("이이는 사,이삼은 육,이사 팔\n");
	}
};

void sub05()
{
	Human h("Mariio", 21);
	Student s("Louiz", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();
}

