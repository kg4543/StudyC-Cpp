#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };

int sub10()
{
	enum season ss;
	char* pc = NULL;

	ss = SPRING;
	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swinming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "sking";
		break;
	}
	printf("���� => %s\n", ss);
	printf("���� ����Ȱ�� => %s\n", pc);

	// enum�� ũ��� 4����Ʈ�� ����
	printf("%d\n", sizeof(ss));

	// ó�� 0���� 1�� ����
	// �߰��� ���ڸ� �ٲٸ� �� ���ں��� �ٽ� 1�� ����
	printf("%d %d %d %d", SPRING, SUMMER, FALL, WINTER); // 0 1 2 3 


	return 0;
}