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
	void eat()
	{
		puts("³È³È³È");
	}
	void intro()
	{
		printf("ÀÌ¸§ = %s, ³ªÀÌ = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage)
	{
		stunum = astunum;
	}
	void intro()
	{
		printf("%dÇÐ¹ø %sÀÔ´Ï´Ù.\n", stunum, name);
	}
};

void sub08()
{
	Human h("Mario", 10);
	Student s("Toad", 15, 123456);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->eat();

	pH = &s;
	pH->intro();
	pH->eat();
}