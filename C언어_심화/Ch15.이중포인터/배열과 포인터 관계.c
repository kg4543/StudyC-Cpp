#include <stdio.h>

int sub5()
{
	printf("\n--------------\n");

	printf("배열 포인터 정리\n\n");

	int a = 10;
	int* pa = &a;
	printf("%p %p\n", &a, pa);
	printf("\n--------------------------------------\n");
	int ary1[2] = { 1,2 };
	int* pary1 = ary1; // int (*pary) = ary 구분하기위해 가로를 치기도 함
	char* pary11 = ary1; // 두 변수 속성이 다르면 주소값이 달라진다.
	printf("%p %p %p\n", ary1, pary1, pary11);
	printf("%p %p %p\n", ary1+1, pary1+1, pary11+1);
	printf("\n-------------------------------------\n");
	char ary2[2] = { 'a','b' };
	char pary2 = ary2;
	printf("%p %p\n", ary2, pary2);
	printf("%p %p\n", ary2 + 1, pary2 + 1);
	printf("\n-------------------------------------\n");
	int ary3[2][2] = { {1,2}, {3,4} };
	int(*pary3)[2] = ary3; //포인트 배열 
	int* pary33 = ary3; 
	printf("%p %p\n", ary3, pary3, pary33);
	printf("%p %p %p\n", ary3 + 1, pary3 + 1, pary33+1); 
	printf("\n-------------------------------------\n");
	char* ary4[2] = { "hi", "good" }; //포인트 배열
	char** pary4 = ary4;
	char* pary44 = ary4;
	printf("%p %p %p\n", ary4, pary4, pary44);
	printf("%p %p %p\n", ary4 + 1, pary4 + 1, pary44+1);

	return 0;
}