#include <stdio.h>
#include <exception>

using namespace std;

void myterm()
{
	puts("ó������ ���� ���� �߻�");
	exit(-1);
}

void sub13()
{
	set_terminate(myterm); //���� ��� �� ����üũ�� ���� �������ϰ� �߻��� �� ����
	try
	{
		throw 1;
	}
	catch (char* m){}
}