#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("%s °´Ã¼ÀÇ »ý¼ºÀÚ°¡ È£ÃâµÇ¾ú½À´Ï´Ù.\n", pname);
	}

	~Human() {
		printf("%s °´Ã¼°¡ ÆÄ±«µÇ¾ú½À´Ï´Ù.\n", pname);
		delete[]pname;
	}

	void intro() {
		printf("ÀÌ¸§ = %s, ³ªÀÌ = %d\n", pname, age);
	}
};

//Human boy("±è»ñ°«", 12); // mainº¸´Ù »¡¸® ½ÇÇà

void sub01()
{
	Human boy("±è»ñ°«", 12);
	boy.intro();
}