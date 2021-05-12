#include <stdio.h>

int* sum(int a, int b);

int sub6()
{
	printf("\n--------------\n");
	
	int* resp;
	resp = sum(10, 20);  //resp는 res값을 가리키는 주소값을 받게된다.
	printf("두 정수의 합 : %d\n", *resp);

	return 0;
}

// Call By Referance  
int* sum(int a, int b)
{
	static int res; // 정적 지역 변수 지정
	//만약 static이 아닐 경우 resp는 존재하지 않는 res를 가리킨다.(실행은 됨) 

	res = a + b;

	return &res; // 정적 지역 변수 반환
}