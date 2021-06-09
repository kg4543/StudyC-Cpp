#include <stdio.h>
#include <exception>

using namespace std;

void myterm()
{
	puts("처리되지 않은 예외 발생");
	exit(-1);
}

void sub13()
{
	set_terminate(myterm); //많이 사용 시 오류체크로 인해 성능저하가 발생할 수 있음
	try
	{
		throw 1;
	}
	catch (char* m){}
}