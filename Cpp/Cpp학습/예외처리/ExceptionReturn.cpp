#include <stdio.h>

int report()
{
	if (true)
	{
		return 1;
	}
	return 0;
}

void sub06()
{
	int e;

	e = report();
	switch (e)
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
	case 4:
		puts("작업을 완료했습니다.");
		break;
	}
}