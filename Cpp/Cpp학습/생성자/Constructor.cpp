#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class CTest {
private:
	int m_num;
	int* ptr;
public:
	int num;

	CTest() { // ����Ʈ ������
		printf("����Ʈ ������ : ���� �����ϴ�.\n");
		num = 0;
		m_num = 0;
	}

	CTest(int num, int c_num = 0) { //�μ��� ������ ������ (��ȯ ������) 
		m_num = num;
		this->num = c_num;
		printf("������ ȣ�� : %d\n", m_num);
	}

	CTest(int num, int* ptr) {  // ���� ������ (���� ����)
		m_num = num;
		ptr = new int;
		this->ptr = ptr;
		printf("���� ������ ȣ�� : %d, %p\n", m_num, this->ptr);
	}

	CTest(CTest& other) {  // ���� ������ (���� ����)
		this->m_num = other.m_num;
		this->ptr = new int;
		this->ptr = ptr;
		num = other.num;
	}

	~CTest() { // �Ҹ���
		printf("�Ҹ��� ȣ�� : %d\n", m_num);
		delete ptr; // �����Ҵ��� ��� �Ҹ��ڿ��� ������Ų��.
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

	CTest c0(100); // �μ� 1�� ������ ȣ��
	CTest c1(50,20); // �μ� 2�� ������ ȣ��
	CTest c2; // ����Ʈ ������ ȣ��
	CTest c3(c1); //���� ������ ȣ�� (���� ����)
	CTest c4(50, nullptr); // ���� ����
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