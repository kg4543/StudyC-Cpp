#include <iostream>
#include <string>
using namespace std;

void sub04()
{
	string s1("test");
	string s2(s1);
	string s3;
	string s4(10,'S');
	string s5("very nice day", 8);
	const char* str = "abcdefghijklmnopqrstuvwxyz"; //����� ������ �Ұ����ϱ� ������ const�� �߰��� �־����
	string s6(str + 5, str + 10); //(ù ���� + 1)6��°���� (������ ����)10��°����
	s3 = "Kupa";

	cout << "s1 =" << s1 << endl;
	cout << "s2 =" << s2 << endl;
	cout << "s3 =" << s3 << endl;
	cout << "s4 =" << s4 << endl;
	cout << "s5 =" << s5 << endl;
	cout << "s6 =" << s6 << endl;

	s3 = "Mario";
	cout << "s3 =" << s3 << endl;
}

/*string�� ������ ���̷� Heap�� �޸𸮸� �Ҵ��Ѵ�. ���۸� �ڵ����� �Ҵ� ����...
ȿ������ �������� ������ �����ϸ� �޸𸮸� ��Ȯ���ؾ���*/