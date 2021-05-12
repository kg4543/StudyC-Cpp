#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub4()
{
	int ch;

	while (1)
	{
		ch = fgetc(stdin);
		if (ch == EOF)
		{
			break;
		}
		fputc(ch, stdout);
	}

	return 0;
}