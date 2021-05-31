#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class NHuman
{
private:
	char* pname;
	int age;

public: 
	NHuman(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("==<%s> 객체 생성==\n", pname);
	}

	~NHuman() {
		printf("==<%s>객체 파괴==\n", pname);
		delete[]pname;
	}

	void intro() {
		printf("이름 =%s, 나이 =%d\n", pname, age);
	}
};

//컴파일러가 생성자와 소멸자를 자동으로 호출

void sub02()
{
	NHuman boy("김삿갓", 12);
	boy.intro();

	NHuman* leo; //동적할당
	leo = new NHuman("레오나르도 다빈치", 40); 
	leo->intro();
	delete leo;
}