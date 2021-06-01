#include <stdio.h>

class Some
{
public:
	const int total;
	Some(int atotal) : total(atotal) {}
	void OutTotal() { printf("%d\n", total); }
};

void sub09()
{
	Some S(5);
	S.OutTotal();
}