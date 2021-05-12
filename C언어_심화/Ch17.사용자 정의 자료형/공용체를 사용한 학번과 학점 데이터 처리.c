#include <stdio.h>

//공용체는 가장큰 변수 크기만큼만 메모리를 할당받아 공유해서 사용
union student 
{
	int num;
	double grade;
};

//가장큰 변수 크기만큼 맴버별 메모리 할당
struct student1
{
	int num;
	double grade;
};

int sub9() 
{
	union student s1 = { 3.15 };
	struct student1 s2;

	printf("학점 : %.2lf\n", s1.grade);
	printf("학번 : %d\n", s1.num);
	
	s1.grade = 4.4;
	printf("학점 : %.1lf\n", s1.grade);
	
	printf("학번 : %d\n", s1.num);
	
	s1.num = 315;
	printf("학번 : %d\n", s1.num);

	printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(s2));

	return 0;
}