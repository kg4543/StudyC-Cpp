#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};


int sub5()
{
	printf("\n--------------\n");

	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("%u\n", ps); 
	printf("%u\n", *ps); 
	printf("%u\n", &ps->kor);
	printf("%u\n", ps->kor);
	
	printf("���� : %d\n", (*ps).kor);
	printf("���� : %d\n", (*ps).eng);
	printf("���� : %d\n", (*ps).math);

	return 0;
}