#include <iostream>
#include <string>

using namespace std;

void sub07()
{
	string name, addr;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "�Է��� �̸��� " << name << "�Դϴ�." << endl;
	cin.ignore();
	cout << "�ּҸ� �Է��Ͻÿ� : ";
	getline(cin, addr);
	cout << "�Է��� �ּҴ� " << addr << "�Դϴ�." << endl;
}