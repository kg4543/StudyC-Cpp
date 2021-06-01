#include <stdio.h>

class Some
{
public:
	int& total;
	Some(int& atotal) : total(atotal) {}
	void OutTotal() { printf("%d\n", total); }
};

void sub10()
{
	int value = 8;
	Some S(value);
	S.OutTotal();
}