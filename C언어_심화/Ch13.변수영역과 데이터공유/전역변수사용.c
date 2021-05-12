#include <stdio.h>

int a;
void assign10(void);
void assign20(void);

int sub2()
{
	printf("\n--------------\n");

	printf("함수 호출 전 a 값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a 값 : %d\n", a); //a는 전역변수 10을 반환
}

void assign10(void)
{
	a = 10;
}
void assign20(void)
{
	int a; // 지역변수로 사용됨

	a = 20;
}