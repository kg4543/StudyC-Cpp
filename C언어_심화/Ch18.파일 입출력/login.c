#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Login ���α׷�
	1. id �� password�� �����ϰ� �����̸��� password.txt�� �����Ѵ�.
	2. ����ü Login ������ id,password �ɹ��� ���� ������ ��Ű��
	3. Ű����� �ԷµǴ� id�� pw�� ���Ͽ� "�α��� �Ǿ����ϴ�."
		�Ǵ� "ID/Password�� ��ġ�����ʽ��ϴ�."��� �޼��� ���
*/

struct Login
{
	char* id;
	char* password;
};


int Login()
{
	// Login �Է� ����
	struct Login user;
	char temp[20];
	int i;

	printf("ID : ");
	gets(temp);
	user.id = (char*)malloc(strlen(temp) + 1);
	strcpy(user.id, temp);
	printf("Password : ");
	gets(temp);
	user.password = (char*)malloc(strlen(temp) + 1);
	strcpy(user.password, temp);

	printf("\n-----------------------\n");
	printf("ID : %s\n Password : %s \n", user.id, user.password);

	//����� ID,Password ���� �ҷ�����
	FILE* ifp;
	ifp = fopen("password.txt", "r");
	int res, res1;
	char tmp1[20];
	char tmp2[20];
	struct Login Info;

	if (ifp == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%s", tmp1, tmp2);
		if (res == EOF) //EOF(End Of File) : -1
		{
			Info.id = (char*)malloc(strlen(tmp1) + 1);
			Info.id = tmp1;
			Info.password = (char*)malloc(strlen(tmp2) + 1);
			Info.password = tmp2;
			break;
		}

	}
	/*printf("���ϰ� : %s %s\n", id, password);
	printf("�Է°� : %s %s\n", user.id, user.password);*/

	if (strcmp(Info.id, user.id) == 0 && strcmp(Info.password, user.password) == 0)
	{
		printf("�α��εǾ����ϴ�.");
	}
	else
	{
		printf("�α��� ����");
	}

	/*if ((*Info.id == *user.id) && (*Info.password == *user.password))
	{
		printf("�α��εǾ����ϴ�.");
	}
	else
	{
		printf("�α��� ����");
	}*/

	fclose(ifp);

	return 0;
}