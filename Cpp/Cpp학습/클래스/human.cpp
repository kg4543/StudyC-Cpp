#include <iostream>

struct Human {
	char name[20];
	float height;
	float weight;
	int age;
	char blood;
	void view();
};

void Human::view() // Human 범위 지정
{
	printf("나의 이름은 %s 이고 키는 %.1f이고 몸무게는 %.1f이고 나이는 %d이고 혈액형은 %c 입니다.\n", name, height, weight, age, blood);
}

void sub01()
{
	Human my = { "Kim", 160, 72, 28, 'O' };
	my.view();
	return;
}