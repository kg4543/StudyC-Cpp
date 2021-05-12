#include <stdio.h>

void auto_func(void);
void static_func(void);

int sub3()
{
	printf("\n--------------\n");

	int i;

	printf("�Ϲ� ���� ����(auto)�� ����� �Լ�...\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("���� ���� ����(static)�� ����� �Լ�...\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func()
{
	auto int a = 0; // �ش� �Լ��� ���� �� �����...���� �Լ��� �ҷ��� ������ ó�� 0������ ����
	a++;
	printf("%d\n", a);
}
void static_func()
{
	static int a = 0; //static ������ main �Լ��� ���� �� �����...�Լ� �ȿ����� ��������
	a++;
	printf("%d\n", a);
}