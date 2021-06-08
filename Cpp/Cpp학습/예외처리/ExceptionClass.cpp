#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class MyClass
{
public:
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

	void calc()
	{
		try
		{
			if (true)
			{
				throw Exception(1);
			}
		}
		catch (Exception &e)
		{
			printf("에러코드 = %d =>", e.GetErrorCode());
			e.ReportError();
		}
	}
	void calc2() throw(Exception)
	{
		if (true)
		{
			throw Exception(2);
		}
	}
};

void sub10()
{
	MyClass m;
	m.calc();
	try
	{
		m.calc2();
	}
	catch (MyClass::Exception &e)
	{
		printf("에러코드 = %d =>", e.GetErrorCode());
		e.ReportError();
	}
}