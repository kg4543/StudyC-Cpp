#include <stdio.h>

class DBQuery
{
private:
	static int hCon;
	int nResult;

public:
	DBQuery() {};
	static void DBConnnect(const char* Server, const char* ID, const char* Pass);
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};

int DBQuery::hCon;

void DBQuery::DBConnnect(const char* Server, const char* ID, const char* Pass)
{
	hCon = 1234;
	puts("연결되었습니다.");
}

void DBQuery::DBDisConnect()
{
	hCon = NULL;
	puts("연결이 끊어졌습니다.");
}

bool DBQuery::RunQuery(const char* SQL)
{
	puts(SQL);
	return true;
}

void sub14()
{
	DBQuery::DBConnnect("Secret", "Adult", "doemfdmsrkfk");
	DBQuery Q1, Q2, Q3;

	Q1.RunQuery("select * from tblBuja where 나랑 친한 사람");

	DBQuery::DBDisConnect();
}