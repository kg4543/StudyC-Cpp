#include <stdio.h>

int sub2()
{
	printf("\n-------------\n");

	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg; // 주소는 4바이트로 고정

	pa = &a; // pa에 a 주소값 대입
	pb = &b; // pb에 b 주소값 대입

	*pt = *pa + *pb; //pt주소의 데이터값 = pa,pb 주소안 데이터 값(a,b)의 합 
	*pg = *pt / 2.0; //pg주소의 데이터값 = pt주소안 데이터값(total) / 2.0

	printf("두 정수의 값 : %d, %d\n", *pa, *pb);
	printf("두 정수의 합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);


	return 0;
}