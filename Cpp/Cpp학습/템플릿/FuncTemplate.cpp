/* 함수 템플릿 */
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

template <> // 특수화
const char* Add(const char* lstr,const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int tlen = llen + rlen + 1; //전체 문자열길이 + Null문자
	char* tstr = new char[tlen]; // 전체 문자열 길이로 할당
	strcpy_s(tstr, llen + 1, lstr); // lstr복사
	strcat_s(tstr, tlen, rstr); // rstr 붙이기
	return tstr;
}

void sub16()
{
	cout << Add(10, 20) << endl;
	cout << Add(3.14, 4.5) << endl;
	const char* str = Add<const char*>("Hello", " IoT"); // 특수화 함수 호출
	cout << str << endl;
	return;
}