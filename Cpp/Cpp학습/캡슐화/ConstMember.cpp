#include <stdio.h>

class MathCalc
{
private:
	const double pie;

public:
	MathCalc(double apie) : pie(apie) {} //초기화가 되기전 생성자 머리에서 미리 초기화
	void DoCalc(double r)
	{
		printf("반지름 %.2f인 원 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

void sub15()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}