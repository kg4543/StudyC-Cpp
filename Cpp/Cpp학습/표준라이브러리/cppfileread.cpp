#include <iostream>
#include <fstream>
using namespace std;

void sub03()
{
	ofstream f; // 생성
	ifstream t; // 읽기
	char str[128];
	int i;

	f.open("c:\\temp\\cpptest1.txt"); // 경로
	t.open("c:\\temp\\cpptest1.txt");
	if (f.is_open())
	{
		f << "HelloWorld " << 1234 << endl;

		t >> str >> i;
		cout << str << i << endl;

		f.close();
	}
	else
	{
		cout << "파일 열기 실패" << endl;
	}
}