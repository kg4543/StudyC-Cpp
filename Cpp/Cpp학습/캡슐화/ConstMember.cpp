#include <stdio.h>

class MathCalc
{
private:
	const double pie;

public:
	MathCalc(double apie) : pie(apie) {} //�ʱ�ȭ�� �Ǳ��� ������ �Ӹ����� �̸� �ʱ�ȭ
	void DoCalc(double r)
	{
		printf("������ %.2f�� �� �ѷ� = %.2f\n", r, r * 2 * pie);
	}
};

void sub15()
{
	MathCalc m(3.1416);
	m.DoCalc(5);
}