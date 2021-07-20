#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Calc
{
public:
	void Op1(int a, int b)
	{
		printf("%d\n", a + b);
	}
	void Op2(int a, int b)
	{
		printf("%d\n", a - b);
	}
	void Op3(int a, int b)
	{
		printf("%d\n", a * b);
	}
};

void main()
{
	int ch;
	Calc c;
	int a = 3, b = 4;

	void (Calc::*arop[3])(int, int)  // :: 범위지정 연산자
	{ 
		&Calc::Op1,
		&Calc::Op2,
		&Calc::Op3
	};

	printf("3 ? 4\n연산 방법을 선택하시오. 0=더하기, 1=빼기, 2=곱하기 : \n");
	scanf("%d", &ch);

	if (ch >= 0 && ch <= 2)
	{
		(c.*arop[ch])(a, b);
	}

	/*switch (ch)
	{
	case 0:
		c.Op1(a, b);
		break;
	case 1:
		c.Op2(a, b);
		break;
	case 2:
		c.Op3(a, b);
		break;
	}*/
}