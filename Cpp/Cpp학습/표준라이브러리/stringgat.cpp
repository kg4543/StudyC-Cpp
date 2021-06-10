#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void sub06()
{
	string s("korea");
	string s2("Josun");
	size_t len;

	len = s.size();
	for (int i = 0; i < len; i++)
	{
		cout << s[i];
	}
	cout << endl;
	s[0] = 'c';

	for (int i = 0; i < len; i++)
	{
		cout << s.at(i);
	}
	cout << endl;

	swap(s, s2);
	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);
	cout << s.data() << endl;
	cout << s.c_str() << endl;
	cout << str << endl;
}