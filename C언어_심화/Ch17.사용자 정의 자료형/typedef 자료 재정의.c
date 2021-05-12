#include <stdio.h>

//공용체는 가장큰 변수 크기만큼만 메모리를 할당받아 공유해서 사용
struct student
{
	int num;
	double grade;
};

typedef struct student Student;
void print_data(Student* ps);

int sub11()
{
	Student s1 = { 315 , 4.4 };

	print_data(&s1);

	return 0;
}

void print_data(Student* ps)
{
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1lf\n", ps -> grade);
}