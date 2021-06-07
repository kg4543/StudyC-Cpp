#include <stdio.h>

class MathCalc
{
private:
	static const double pie;
	static const int sint = 3;

public:
	MathCalc() {};
	void DoCalc(double r)
	{
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;

void main()
{
	MathCalc m;
	m.DoCalc(5);
}