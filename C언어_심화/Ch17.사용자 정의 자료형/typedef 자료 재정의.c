#include <stdio.h>

//����ü�� ����ū ���� ũ�⸸ŭ�� �޸𸮸� �Ҵ�޾� �����ؼ� ���
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
	printf("�й� : %d\n", ps->num);
	printf("���� : %.1lf\n", ps -> grade);
}