#include <stdio.h>

int ar[] = { 1,2,3,4,5 };

int &GetAr(int i)
{
	return ar[i];
}

void sub11()
{
	//int ra = 10; 
	//상수(rvalue)는 레퍼런스로 지정 불가 : lvalue(변수)만 가능
	GetAr(3) = 6;
	printf("ar[3] = %d\n", ar[3]);
}