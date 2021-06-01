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
		strcpy(this->name, name); // this. 객체 자신
		this->age = age;
	}
	void intro() {
		printf("이름 = %s,나이 = %d\n", name, age);
	}
};

void sub07()
{
	Human kim("김상형", 29);
	kim.intro();
}