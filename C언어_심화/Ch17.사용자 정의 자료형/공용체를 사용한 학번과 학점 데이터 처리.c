#include <stdio.h>

//����ü�� ����ū ���� ũ�⸸ŭ�� �޸𸮸� �Ҵ�޾� �����ؼ� ���
union student 
{
	int num;
	double grade;
};

//����ū ���� ũ�⸸ŭ �ɹ��� �޸� �Ҵ�
struct student1
{
	int num;
	double grade;
};

int sub9() 
{
	union student s1 = { 3.15 };
	struct student1 s2;

	printf("���� : %.2lf\n", s1.grade);
	printf("�й� : %d\n", s1.num);
	
	s1.grade = 4.4;
	printf("���� : %.1lf\n", s1.grade);
	
	printf("�й� : %d\n", s1.num);
	
	s1.num = 315;
	printf("�й� : %d\n", s1.num);

	printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(s2));

	return 0;
}