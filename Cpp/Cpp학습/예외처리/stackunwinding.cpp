#include <stdio.h>

class C
{
	int a;

public:
	C() { puts("������ ȣ��"); }
	~C() { puts("�ı��� ȣ��"); }
};

void divide1(int a, int b)
{
	if (b == 0)
	{
		throw "0���δ� ���� �� �����ϴ�.\n";
	}
	printf("������ ��� %d�Դϴ�.\n", a / b);
}

void calc(int t, const char* m)
{
	C c; // ������ ȣ��
	divide1(10, 5); // ����
	divide1(10, 0); // �ı���ȣ�� �� ���ܹ߻� catch������
	divide1(10, 5); // ���� �ȵ�
}

void sub03()
{
	try 
	{
		calc(1, "���");
	}
	catch (const char* message)
	{
		puts(message);
	}
	puts("���α׷��� ����˴ϴ�.");
}