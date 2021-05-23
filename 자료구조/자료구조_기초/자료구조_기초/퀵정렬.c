 /*
 �� ���� : ���� ���� �˰���
 ������ ���� �ȵǾ� ������ ���� ����
 ������� ���ĵǾ� ������ ���������� �� ����

 ��� ���� ũ�� ������ ������ ���� (�ݺ�)

 1. ���ҵ� �߿��� pivot�� ����
 2. �� pivot�� �������� �տ��� ���� ��, �ڿ��� ū ������ ��ġ��Ų��.(����)
 3. ���ҵ� ���� ����Ʈ�� ��������� ������ ��Ų��.(����)
 4. ���ĵ� ���� ����Ʈ���� �����Ѵ�.(����)
 */
#include <stdio.h>

void quickSort(int*, int, int);

void sub25()
{
	int ary[] = { 3,5,2,4,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int i;

	for (i = 0; i < size; i++) // ó�� ���
	{
		printf("%5d", ary[i]);
	}
	
	quickSort(ary, 0, size-1);
	printf("\n\n---------------���� ��---------------\n\n");
	
	for (i = 0; i < size; i++) // ������ ���
	{
		printf("%5d", ary[i]);
	}
	printf("\n");

	return;
}

void quickSort(int* pary, int left, int right)
{
	if (left >= right)
		return;
	int pivot = left;
	int mleft = pivot + 1;
	int mright = right;
	int temp;
	int i;

	while (mleft <= mright) //mleft�� mright�� ��ü�� �� �ɶ� ����
	{
		while (pary[mleft] <= pary[pivot])
			mleft++;
		while (pary[mright] >= pary[pivot] && mright > left)
			mright--;

		if (mleft > mright)
		{
			temp = pary[mright];
			pary[mright] = pary[pivot];
			pary[pivot] = temp;
		}
		else {
			temp = pary[mright];
			pary[mright] = pary[mleft];
			pary[mleft] = temp;
		}
	}

	quickSort(pary, left, mright - 1);
	quickSort(pary, mright + 1, right);
}