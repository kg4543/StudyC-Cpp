#include <stdio.h>

class Simple
{
private:
	int value;

public:
	Simple(int avalue) : value(avalue) {}

	void OutValue() {
		printf("value = %d\n", value);
	}
};

void sub08()
{
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
	A.OutValue();
}