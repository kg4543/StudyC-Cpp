#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SUM(a,b) ((a)+(b))
#define MUL(a,b) ((a)*(b))
// 인수별로 가로()를 해주어야 제대로 값이 나옴
// 매크로함수는 추천하는 방식은 아님

int sub2()
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + y = %d\n", SUM(x, y));
	res = 30 / MUL(2, 5);
	printf("res : %d\n", res);

	return 0;
}