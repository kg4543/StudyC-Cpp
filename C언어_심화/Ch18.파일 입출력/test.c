#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Login 프로그램
	1. id 와 password를 저장하고 파일이름은 password.txt로 저장한다.
	2. 구조체 Login 변수에 id,password 맴버에 각각 저장을 시키고
	3. 키보드로 입력되는 id와 pw를 비교하여 "로그인 되었습니다."
		또는 "ID/Password가 일치하지않습니다."라는 메세지 출력
*/

struct Login
{
	char* id;
	char* password;
};


int Test()
{
	// Login 입력 정보
	struct Login user;
	char temp[20];
	int i;

	printf("ID : ");
	gets(temp);
	user.id = (char*)malloc(strlen(temp)+1);
	strcpy(user.id, temp);
	printf("Password : ");
	gets(temp);
	user.password = (char*)malloc(strlen(temp)+1);
	strcpy(user.password, temp);

	printf("\n-----------------------\n");
	printf("ID : %s\n Password : %s \n", user.id, user.password);

	//저장된 ID,Password 파일 불러오기
	FILE* ifp;
	ifp = fopen("password.txt", "r");
	int res, res1;
	char tmp[20];
	char *id = "";
	char *password = "";

	if (ifp == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s", tmp);
		if (res == EOF) //EOF(End Of File) : -1
		{
			break;
			/*id = (char*)malloc(strlen(tmp) + 1);
			strcpy(id, tmp);
			password = (char*)malloc(strlen(tmp) + 1);
			strcpy(password, tmp);*/
		}
	}
	printf("파일값 : %s %s\n", tmp);
	printf("입력값 : %s %s\n", user.id, user.password);


	if (strcmp(id, user.id) == 0 && strcmp(password, user.password) == 0)
	{
		printf("로그인되었습니다.");
	}
	else
	{
		printf("로그인 실패");
	}

	fclose(ifp);

	return 0;
}
