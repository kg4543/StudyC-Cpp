#include <iostream>
#include <fstream>
using namespace std;

void sub03()
{
	ofstream f; // ����
	ifstream t; // �б�
	char str[128];
	int i;

	f.open("c:\\temp\\cpptest1.txt"); // ���
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
		cout << "���� ���� ����" << endl;
	}
}