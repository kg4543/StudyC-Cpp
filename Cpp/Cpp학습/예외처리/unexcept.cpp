#include <stdio.h>
#include <exception>
using namespace std;

void myunex()
{
	puts("발생해서는 안 되는 에러 발생");
	exit(-2);
}

void calc() throw(int)
{
	//throw "string"; 지정하지 않은 예외발생으로 오류 발생
	throw 10;
}

void sub14()
{
	set_unexpected(myunex);
	try
	{
		calc();
	}
	catch (int)
	{
		puts("정수형 예외 발생");
	}
	puts("프로그램 종료");
}