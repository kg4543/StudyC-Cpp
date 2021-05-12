#include <stdio.h>
#pragma pack(push, 1)

typedef struct
{
	char ch;
	int in;
}Sample1;

#pragma pack(pop)
typedef struct
{
	char ch;
	int in;
}Sample2;

int sub6()
{
	printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	return 0;
}