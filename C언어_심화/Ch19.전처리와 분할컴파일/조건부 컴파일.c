#include <stdio.h>
#define VER 7
#define BTT16

int sub5()
{
	int max;

#if VER >= 6
	printf("���� %d�Դϴ�.\n", VER);
#endif

#ifndef BTT16 //if n(not) def(define)
	max = 32767;
	#else// BTT16
		max = 2147483647;
#endif

	printf("int�� ������ �ִ밪 : %d\n", max);

	return 0;
}