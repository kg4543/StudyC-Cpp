#include <stdio.h>

void QuickSort(int*, int, int);

void sub26()
{
	int ary[] = { 3,5,2,4,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int i;

	for (i = 0; i < size; i++) // ó�� ���
	{
		printf("%5d", ary[i]);
	}

	printf("\n\n---------------���� ��---------------\n\n");
	
	QuickSort(ary, 0, size - 1); // ������ ó��, ������ ������ ����Ű�� index ����

	for (i = 0; i < size; i++) // ������ ���
	{
		printf("%5d", ary[i]);
	}
	printf("\n");

	

	return;
}

void QuickSort(int* pary, int left, int right)
{
	if (left + 1 >= right) //���̰� 1 �Ǵ� 2�� �� return
		return;

	int pivot = right / 2;  // �迭�� �߰������� pivot���� ����
	int mleft = left; // ó�� �������� ���� �÷����鼭 pivot�� ��
	int mright = right; // ������ �������� ���� �ٿ����鼭 pivot�� ��
	int temp; // ���� swap�ϱ� ���� �����

	while (mleft <= mright)
	{
		while (pary[mleft] <= pary[pivot]) //ó�� �������� �߰������� ū ���� ���� ������ index++
			mleft++;
		while (pary[mright] >= pary[pivot]) //������ �������� �߰������� ���� ���� ���� ������ index--
			mright--;

		// ������ ��(�߰����� ��,�� ��)�� �ٲ���
		if (mleft <= mright) //mleft�� mright���� Ŭ ��� ��ü���� �ʰ� while���� �������´�.
		{
			temp = pary[mleft];
			pary[mleft] = pary[mright];
			pary[mright] = temp;
		}
	}

	int i;
	for (i = 0; i < right+1; i++) // �߰� ���
	{
		printf("%5d", pary[i]);
	}
	printf("\n");

	QuickSort(pary, left, --mleft);
	QuickSort(pary, ++mright, right);
}