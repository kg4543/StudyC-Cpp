#include <stdio.h>

class C
{
	int a;

public:
	C() { puts("생성자 호출"); }
	~C() { puts("파괴자 호출"); }
};

void divide1(int a, int b)
{
	if (b == 0)
	{
		throw "0으로는 나눌 수 없습니다.\n";
	}
	printf("나누기 결과 %d입니다.\n", a / b);
}

void calc(int t, const char* m)
{
	C c; // 생성자 호출
	divide1(10, 5); // 실행
	divide1(10, 0); // 파괴자호출 후 예외발생 catch문으로
	divide1(10, 5); // 실행 안됨
}

void sub03()
{
	try 
	{
		calc(1, "계산");
	}
	catch (const char* message)
	{
		puts(message);
	}
	puts("프로그램이 종료됩니다.");
}