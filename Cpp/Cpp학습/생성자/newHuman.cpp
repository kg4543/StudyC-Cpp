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
		printf("==<%s> ��ü ����==\n", pname);
	}

	~NHuman() {
		printf("==<%s>��ü �ı�==\n", pname);
		delete[]pname;
	}

	void intro() {
		printf("�̸� =%s, ���� =%d\n", pname, age);
	}
};

//�����Ϸ��� �����ڿ� �Ҹ��ڸ� �ڵ����� ȣ��

void sub02()
{
	NHuman boy("���", 12);
	boy.intro();

	NHuman* leo; //�����Ҵ�
	leo = new NHuman("���������� �ٺ�ġ", 40); 
	leo->intro();
	delete leo;
}