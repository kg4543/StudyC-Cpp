#include <stdio.h>

void sub2()
{
	int i, length = 0;
	char str[50];
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(str);
	printf("�Էµ� ���ڿ��� \n \"");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n�Դϴ�.");
	printf("\n\n �Էµ� ���ڿ��� ���� = %d \n", length);

	getchar();
}