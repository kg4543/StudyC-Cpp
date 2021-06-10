#include <iostream>
#include <string>
using namespace std;

void sub09()
{
	auto_ptr<double> rate(new double);

	*rate = 3.1415;
	cout << *rate << endl;

	auto_ptr<string>pStr(new string("AutoPtr Test"));

	cout << *pStr << endl;
}
