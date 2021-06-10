#include <iostream>
#include <vector>
using namespace std;

void sub11()
{
	vector<int> v;
	
	v.push_back(10);
	vector<int> ::iterator iter = v.begin();
	iter = v.insert(iter, 2);

	v.pop_back();
	v.erase(v.begin() + 10);
	v.clear();

	vector<int> x = { 10,20,30,40,50 };
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << ' ';
	}
}