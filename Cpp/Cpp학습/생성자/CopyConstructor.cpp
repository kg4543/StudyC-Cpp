#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class sHuman
{
private:
	char* pname;
	int age;

public:
	sHuman(const char* aname, int aage)
	{
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	sHuman(const sHuman& other) {
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~sHuman() {
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printsHuman(sHuman who) {
	who.intro();
}

void sub07()
{
	sHuman kang("강감찬", 1424);
	sHuman boy = kang;

	printsHuman(boy);
}