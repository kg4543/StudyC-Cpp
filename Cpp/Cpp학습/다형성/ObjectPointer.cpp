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
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
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
		printf("%d 학번 %s입니다.\n", stunum, name);
	}
	void study()
	{
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

void sub02()
{
	Human h("Mario", 10);
	Student s("Peach", 15, 1234567);
	Human* pH;
	Student* pS;

	pH = &h;
	pS = &s;
	pH = &s;

	// pS = &h; 
	pS = (Student*)&h; //Downcasting:자식이 형변환하여 부모를 가리키는 형태
	
	pS->intro();
}