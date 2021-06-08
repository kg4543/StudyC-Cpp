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
			puts("메모리가 부족합니다.");
			break;
		case 2:
			puts("연산 범위를 초과했습니다.");
			break;
		case 3:
			puts("하드디스크가 가득 찼습니다.");
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
		puts("작업을 완료했습니다.");
	}
	catch (Exception &e)
	{
		printf("에러 코드 = %d => ", e.GetErrorCode());
		e.ReportError();
	}
}