#include <stdio.h>

void function(); // �Լ� ����

int sub0(void) 
{

	function();

	return 0;
}

void function() {

	int a = 10, b = 10;
	int res;

	res = a + b;
	printf("res: %d", res);
}