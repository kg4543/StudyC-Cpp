#include <stdio.h>

int sub0()
{
	printf("\n--------------\n");

	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int)); //�޸� ���� �Ҵ� �� �����ͷ� ����; (int*) : ��������
	if (pi == NULL)
	{
		printf("# �޸𸮰� �����մϴ�.\n");
		exit(1);
	}
	pd = (double*)malloc(sizeof(double));

	*pi = 10;
	*pd = 3.4; // ���� �Ҵ� ���� ���

	printf("���������� ��� : %d\n", *pi);
	printf("�Ǽ������� ��� : %.1lf\n", *pd);

	free(pi);
	free(pd);  // ���� �Ҵ� ���� ��ȯ

	return 0;
}
