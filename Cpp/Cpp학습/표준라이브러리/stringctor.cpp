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
	const char* str = "abcdefghijklmnopqrstuvwxyz"; //상수로 변경이 불가능하기 때문에 const를 추가해 주어야함
	string s6(str + 5, str + 10); //(첫 범위 + 1)6번째부터 (마지막 범위)10번째까지
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

/*string은 가변적 길이로 Heap에 메모리를 할당한다. 버퍼를 자동으로 할당 관리...
효율성은 떨어지기 때문에 가능하면 메모리를 정확히해야함*/