#include <stdio.h>

int sub2()
{
	printf("\n-------------\n");

	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	int* pt = &total;
	double* pg = &avg; // �ּҴ� 4����Ʈ�� ����

	pa = &a; // pa�� a �ּҰ� ����
	pb = &b; // pb�� b �ּҰ� ����

	*pt = *pa + *pb; //pt�ּ��� �����Ͱ� = pa,pb �ּҾ� ������ ��(a,b)�� �� 
	*pg = *pt / 2.0; //pg�ּ��� �����Ͱ� = pt�ּҾ� �����Ͱ�(total) / 2.0

	printf("�� ������ �� : %d, %d\n", *pa, *pb);
	printf("�� ������ �� : %d\n", *pt);
	printf("�� ������ ��� : %.1lf\n", *pg);


	return 0;
}