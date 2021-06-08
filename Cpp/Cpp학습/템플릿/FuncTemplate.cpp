/* �Լ� ���ø� */
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

template <> // Ư��ȭ
const char* Add(const char* lstr,const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int tlen = llen + rlen + 1; //��ü ���ڿ����� + Null����
	char* tstr = new char[tlen]; // ��ü ���ڿ� ���̷� �Ҵ�
	strcpy_s(tstr, llen + 1, lstr); // lstr����
	strcat_s(tstr, tlen, rstr); // rstr ���̱�
	return tstr;
}

void sub16()
{
	cout << Add(10, 20) << endl;
	cout << Add(3.14, 4.5) << endl;
	const char* str = Add<const char*>("Hello", " IoT"); // Ư��ȭ �Լ� ȣ��
	cout << str << endl;
	return;
}