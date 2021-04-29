#include <stdio.h>

void function(); // 함수 선언

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