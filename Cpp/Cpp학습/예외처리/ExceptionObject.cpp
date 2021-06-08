#include <stdio.h>

class Exception
{
private:
	int ErrorCode;

public:
	Exception(int ae) : ErrorCode(ae) {}
	int GetErrorCode() { return ErrorCode; }
	void ReportError()
	{
		switch (ErrorCode)
		{
		case 1:
			puts("�޸𸮰� �����մϴ�.");
			break;
		case 2:
			puts("���� ������ �ʰ��߽��ϴ�.");
			break;
		case 3:
			puts("�ϵ��ũ�� ���� á���ϴ�.");
			break;
		}
	}
};

void report1()
{
	if (true)
	{
		throw Exception(3);
	}
}

void sub08()
{
	try
	{
		report1();
		puts("�۾��� �Ϸ��߽��ϴ�.");
	}
	catch (Exception &e)
	{
		printf("���� �ڵ� = %d => ", e.GetErrorCode());
		e.ReportError();
	}
}