#include <stdio.h>

enum E_Error{OUTOFMEMORY, OVERRANGE, HARDFULL};
void report() throw(E_Error)
{
	if (true)
	{
		throw OVERRANGE;
	}
}

void sub07()
{
	try
	{
		report();
		puts("작업을 완료하였습니다.");
	}
	catch (E_Error e)
	{
		switch (e)
		{
		case OUTOFMEMORY:
			puts("메모리가 부족합니다.");
			break;
		case OVERRANGE:
			puts("연산 범위를 초과했습니다.");
			break;
		case HARDFULL:
			puts("하드디스크가 가득 찼습니다.");
			break;
		}
	}
}