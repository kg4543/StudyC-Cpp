#include <stdio.h>

class StaticTest {
public:
	int a;
	static int b; // static �ɹ����� ����
	StaticTest() {
		a = 10;
		//b = 20; Ŭ���� ���ο��� �ʱ�ȭ �Ұ� 
		b++;
	}

	void getData() {
		printf("a : %d, b : %d\n", a, b);
	}
};

int StaticTest::b = 20; // static ������� �ʱ�ȭ (�ܺο��� �ʱ�ȭ�ȴ�.) -��ü���� �������� �ʴ´�.

void sub10()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	return;
}