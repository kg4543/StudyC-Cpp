#include <stdio.h>

int sub5()
{
	printf("\n--------------\n");

	printf("�迭 ������ ����\n\n");

	int a = 10;
	int* pa = &a;
	printf("%p %p\n", &a, pa);
	printf("\n--------------------------------------\n");
	int ary1[2] = { 1,2 };
	int* pary1 = ary1; // int (*pary) = ary �����ϱ����� ���θ� ġ�⵵ ��
	char* pary11 = ary1; // �� ���� �Ӽ��� �ٸ��� �ּҰ��� �޶�����.
	printf("%p %p %p\n", ary1, pary1, pary11);
	printf("%p %p %p\n", ary1+1, pary1+1, pary11+1);
	printf("\n-------------------------------------\n");
	char ary2[2] = { 'a','b' };
	char pary2 = ary2;
	printf("%p %p\n", ary2, pary2);
	printf("%p %p\n", ary2 + 1, pary2 + 1);
	printf("\n-------------------------------------\n");
	int ary3[2][2] = { {1,2}, {3,4} };
	int(*pary3)[2] = ary3; //����Ʈ �迭 
	int* pary33 = ary3; 
	printf("%p %p\n", ary3, pary3, pary33);
	printf("%p %p %p\n", ary3 + 1, pary3 + 1, pary33+1); 
	printf("\n-------------------------------------\n");
	char* ary4[2] = { "hi", "good" }; //����Ʈ �迭
	char** pary4 = ary4;
	char* pary44 = ary4;
	printf("%p %p %p\n", ary4, pary4, pary44);
	printf("%p %p %p\n", ary4 + 1, pary4 + 1, pary44+1);

	return 0;
}