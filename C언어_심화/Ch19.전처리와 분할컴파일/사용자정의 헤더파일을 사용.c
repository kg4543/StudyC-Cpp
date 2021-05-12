#include <stdio.h>
#include "student.h"

int sub0()
{
	Student a = { 315,"홍길동" };

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);
}