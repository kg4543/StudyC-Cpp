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
		printf("생성\n");
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
		printf("소멸\n");
	}

	void outinfo()
	{
		printf("이름: %s, 나이: %d\n", name, age);
	}
};

void sub03()
{
	Human man1("Kim", 21);
	man1.outinfo();
}
