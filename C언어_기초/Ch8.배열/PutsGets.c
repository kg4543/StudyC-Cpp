#include<stdio.h>

int sub6(void)
{
	printf("\n-------------\n");

	char str[80];
	printf("���ڿ� �Է� : ");
	gets(str); //��ĭ�� ������ ���ڿ� �Է�
	puts("�Էµ� ���ڿ� : "); //�ڵ����� ������ �����ش�. ���ڿ��� ����ϱ� ������ printf���� ����
	puts(str); //���ڿ� ���

	return 0;
}