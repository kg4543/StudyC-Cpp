#include <stdio.h>

void auto_func(void);
void static_func(void);

int sub3()
{
	printf("\n--------------\n");

	int i;

	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}

	return 0;
}

void auto_func()
{
	auto int a = 0; // 해당 함수가 끝날 때 사라짐...따라서 함수를 불러올 때마다 처음 0값으로 생성
	a++;
	printf("%d\n", a);
}
void static_func()
{
	static int a = 0; //static 변수는 main 함수가 끝날 때 사라짐...함수 안에서만 수정가능
	a++;
	printf("%d\n", a);
}