#include <iostream>

struct Human {
	char name[20];
	float height;
	float weight;
	int age;
	char blood;
	void view();
};

void Human::view() // Human ���� ����
{
	printf("���� �̸��� %s �̰� Ű�� %.1f�̰� �����Դ� %.1f�̰� ���̴� %d�̰� �������� %c �Դϴ�.\n", name, height, weight, age, blood);
}

void sub01()
{
	Human my = { "Kim", 160, 72, 28, 'O' };
	my.view();
	return;
}