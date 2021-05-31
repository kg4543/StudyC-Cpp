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
		printf("이름 =%s, 나이 =%d\n", pname, age);
	}
};

// 동적할당 햇던 값도 소멸자로 삭제가 되어 메모리 해제가 됨 (에러발생)
void sub06()
{
	CHuman kang("강감찬", 1424);
	CHuman boy = kang;

	boy.intro();
}