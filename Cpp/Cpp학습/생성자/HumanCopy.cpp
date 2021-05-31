#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class CHuman
{
private:
	char* pname;
	int age;

public:
	CHuman(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	~CHuman() {
		delete[]pname;
	}

	void intro() {
		printf("�̸� =%s, ���� =%d\n", pname, age);
	}
};

// �����Ҵ� �޴� ���� �Ҹ��ڷ� ������ �Ǿ� �޸� ������ �� (�����߻�)
void sub06()
{
	CHuman kang("������", 1424);
	CHuman boy = kang;

	boy.intro();
}