#include <iostream>
#include <string>

using namespace std;

void sub05()
{
	string s("C++ string");

	cout << s << "문자열의 길이 = " << s.size() << endl;
	cout << s << "문자열의 길이 = " << s.length() << endl;
	cout << s << "문자열의 할당 크기 = " << s.capacity() << endl;
	cout << s << "문자열의 최대 길이 = " << s.max_size() << endl;

	s.resize(6);
	cout << s << "길이 = " << s.size() << ",할당크기 =" << s.capacity() << endl;
	
	s.resize(100);
	cout << s << "길이 = " << s.size() << ",할당크기 =" << s.capacity() << endl;
	s.clear();
	cout << s << "길이 = " << s.size() << ",할당크기 =" << s.capacity() << endl;
}