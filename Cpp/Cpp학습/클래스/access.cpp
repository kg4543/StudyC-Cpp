#include <stdio.h>

/*
default 값
구조체 : public
클래스 : private
*/

struct SAHuman
{
int age;

private:
	char name[12];

public:
	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

void sub03()
{
	SAHuman kim;
	//kim.name = "kim";
	kim.age = 28;
	kim.intro();
}