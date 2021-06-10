#include <iostream>
#include <string>
using namespace std;

void sub08()
{
	string s1("1234567890");
	string s2("abcdefghijklmnopqrstuvwxyz");
	string s3;

	s3.assign(s1, 3, 4);
	cout << s3 << endl;
	s3.append(s2, 10, 7);
	cout << s3 << endl;

	printf("==============================\n");
	// 삽입 삭제 교체
	string s4("^_^;");

	cout << s1 << endl;
	s1.insert(5, "XXX");
	cout << s1 << endl;
	s1.insert(5, s4);
	cout << s1 << endl;
	s1.erase(5, 6);
	cout << s1 << endl;
	s1.replace(5, 2, "super"); // 시작점 , 교체대 사라질 것들 , 새로 교체할 것
	cout << s1 << endl;
	string s5 = s1.substr(5, 5); // 시작점, 추출할 문자열 길이
	cout << s5 << endl; 

	printf("==============================\n");
	//compare 비교
	string  s6("111");
	string  s7("111\n");
	string  s8("112");

	cout << (s6 == s6 ? "O" : "X") << endl;
	cout << (s6 == s7 ? "O" : "X") << endl;
	cout << (s6 == s7 ? "O" : "X") << endl;
	cout << (s7 > s8 ? "O" : "X") << endl;
	cout << (s6 == "111" ? "O" : "X") << endl;
	cout << (s6.compare(s7) == 0 ? "O" : "X") << endl;

	printf("==============================\n");
	//find 찾기
	string s9("string class find function");
	string s10("func");

	cout << "i:" << s9.find("i") << "번째" << endl;
	cout << "i:" << s9.find("i", 10) << "번째" << endl;
	cout << "find:" << s9.find("find", 10) << "번째" << endl;
	cout << "finding의 앞 4:" << s9.find("finding", 0, 4) << "번째" << endl;
	cout << "s2:" << s9.find(s10) << "번째" << endl;
}