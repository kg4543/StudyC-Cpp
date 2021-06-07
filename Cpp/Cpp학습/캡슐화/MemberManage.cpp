#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class CMember
{
private:
	char name[12];
	char phone[12];
	char addr[100];
	static int cnt;

public:
	CMember(const char* aname, const char* aphone, const char* aaddr) 
	{
		strncpy(name, aname, 12);
		strncpy(phone, aphone, 12);
		strcpy(addr, aaddr);
		cnt++; 
	}
	~CMember() { cnt--; }

	void getData()
	{
		printf("이름 = %s, 전화번호 = %s, 주소 = %s\n", name, phone, addr);
	}
	static void InitCnt()
	{
		cnt = 0;
	}
	static void outCnt()
	{
		printf("전체 회원 수 = %d 명\n", cnt);
	}
};

int CMember::cnt;

void sub13()
{
	CMember::InitCnt();
	CMember* pm1 = new CMember("Mario", "01054278282", "부산광역시");
	CMember* pm2 = new CMember ("Zelda", "01092825431", "서울특별시");

	pm1->getData();
	pm2->getData();
	
	CMember::outCnt();

	delete pm1;
	delete pm2;
	
	CMember::outCnt();
}