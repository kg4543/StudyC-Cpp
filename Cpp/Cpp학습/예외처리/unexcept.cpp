#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("�߻��ؼ��� �� �Ǵ� ���� �߻�");
	exit(-2);
}

void calc() throw(int)
{
	//throw "string"; �������� ���� ���ܹ߻����� ���� �߻�
	throw 10;
}

void sub14()
{
	set_unexpected(myunex);
	try
	{
		calc();
	}
	catch (int)
	{
		puts("������ ���� �߻�");
	}
	puts("���α׷� ����");
}