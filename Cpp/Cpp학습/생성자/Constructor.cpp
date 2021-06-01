#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class CTest {
private:
	int m_num;
	int* ptr;
public:
	int num;

	CTest() { // 디폴트 생성자
		printf("디폴트 생성자 : 값이 없습니다.\n");
		num = 0;
		m_num = 0;
	}

	CTest(int num, int c_num = 0) { //인수를 가지는 생성자 (변환 생성자) 
		m_num = num;
		this->num = c_num;
		printf("생성자 호출 : %d\n", m_num);
	}

	CTest(int num, int* ptr) {  // 복사 생성자 (깊은 복사)
		m_num = num;
		ptr = new int;
		this->ptr = ptr;
		printf("복사 생성자 호출 : %d, %p\n", m_num, this->ptr);
	}

	CTest(CTest& other) {  // 복사 생성자 (얕은 복사)
		this->m_num = other.m_num;
		this->ptr = new int;
		this->ptr = ptr;
		num = other.num;
	}

	~CTest() { // 소멸자
		printf("소멸자 호출 : %d\n", m_num);
		delete ptr; // 동적할당한 경우 소멸자에서 해제시킨다.
	}

	void getData() {
		printf("private : %d, %p\n", m_num, ptr);
	}
};

void sub08()
{
	int a = 10;
	int b(20);
	int c = a;
	int* p = nullptr;

	printf("%d, %d, %d\n", a, b, c);

	CTest c0(100); // 인수 1개 생성자 호출
	CTest c1(50,20); // 인수 2개 생성자 호출
	CTest c2; // 디폴트 생성자 호출
	CTest c3(c1); //복사 생성자 호출 (얕은 복사)
	CTest c4(50, nullptr); // 깊은 복사
	CTest c5(100, p);

	printf("=======================\n");
	printf("c0.num\n");
	printf("public : %d\n", c0.num);
	c0.getData();
	printf("=======================\n");
	printf("c1.num\n");
	printf("public : %d\n", c1.num);
	c1.getData();
	printf("=======================\n");
	printf("c2.num\n");
	printf("public : %d\n", c2.num);
	c2.getData();
	printf("=======================\n");
	printf("c3.num\n");
	printf("public : %d\n", c3.num);
	c3.getData();
	printf("=======================\n");
	printf("c4.num\n");
	printf("public : %d\n", c4.num);
	c4.getData();
	printf("=======================\n");
	printf("c5.num\n");
	printf("public : %d\n", c5.num);
	c5.getData();
	printf("=======================\n");

	return;
}