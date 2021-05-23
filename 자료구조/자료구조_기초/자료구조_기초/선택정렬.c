//�������� : 0������ �ּҰ��̶�� �����ϰ� ������ ���ҵ�� ���Ͽ� ��ü�Ѵ�.
#include <stdio.h>

void SelectionSort(int* pary, int size);

void sub24()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	SelectionSort(ary, size);

	return 0;
}

void SelectionSort(int* pary, int size)
{
	int i, j, k, min, temp;
	for (i = 0; i < size - 1; i++)
	{
		min = i; // ���� ó���� �ּҷ� ����
		for (j = i + 1; j < size; j++) //2��° ������ �� ����
		{
			if (pary[min] > pary[j]) // ���� ù��° ���� �� Ŭ ���
			{
				min = j; // �ּҸ� ����
			}
		}
		temp = pary[min]; // �ּҰ��� �ڸ� ����
		pary[min] = pary[i];
		pary[i] = temp;
		printf("\n%d �ܰ� : ", i + 1);
		for (k = 0; k < size; k++)
		{
			printf("%5d", pary[k]);
		}
	}
}