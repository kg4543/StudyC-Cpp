#include <stdio.h>

int LinearSearch(int* pary, int size, int data);

void sub21()
{
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int index; //�˻� �� �迭�� ����
	int size = sizeof(ary) / sizeof(ary[0]);
	int data = 8; // �˻���
	
	//�˻�
	index = LinearSearch(ary, size, data);

	//���
	if (index == -1)
	{
		printf("ã�� ���� �����ϴ�.");
	}
	else
	{
		printf("%d��° �� : %d", index + 1, ary[index]);
	}

	return;
}

int LinearSearch(int* pary, int size, int data)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		if (data == pary[i])
		{
			return i; // ã�� ���� ����
		}
	}
	return -1; // ���� ���� ���
}