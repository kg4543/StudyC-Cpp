#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class AHuman
{
private:
	char name[12];
	int age;

public:
	AHuman(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("�̸� = %s,���� = %d\n", name, age);
	}
};

void sub04()
{
	AHuman arFriend[3] = {
		{AHuman("������",49)},
		{AHuman("������",49)},
		{AHuman("�ڻ�",49)}
	};

	arFriend[2].intro();
}