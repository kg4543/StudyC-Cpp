#include <stdio.h>

int* sum(int a, int b);

int sub6()
{
	printf("\n--------------\n");
	
	int* resp;
	resp = sum(10, 20);  //resp�� res���� ����Ű�� �ּҰ��� �ްԵȴ�.
	printf("�� ������ �� : %d\n", *resp);

	return 0;
}

// Call By Referance  
int* sum(int a, int b)
{
	static int res; // ���� ���� ���� ����
	//���� static�� �ƴ� ��� resp�� �������� �ʴ� res�� ����Ų��.(������ ��) 

	res = a + b;

	return &res; // ���� ���� ���� ��ȯ
}