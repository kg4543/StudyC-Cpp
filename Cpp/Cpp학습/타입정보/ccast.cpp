#include <stdio.h>

class Parent {};
class Child : public Parent {};

void sub05()
{
	const char* str = "korea";
	int* pi;
	double d = 123.456;
	int i;

	int ary[] = { 1,2,3,4,5 };
	int* ptr = static_cast<int*>(ary);
	i = static_cast<int>(d);

	//pi = static_cast<int*>(str); : static_cast는 포이터끼리는 불가
	pi = (int*)str;
	printf("%d %x\n",*pi,*pi);

	Parent P, * pP;
	Child C, * pC;
	int j = 1234;

	pP = static_cast<Parent *>(&C);
	// 부모포인터가 자식을 가리키는게 기본
	/*pC = static_cast<Parent *>(&P);
	pP = static_cast<Parent *>(&j);
	pC = static_cast<Parent *>(&j);*/
}